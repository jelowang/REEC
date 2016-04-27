

/*

+	Regular Expression Engine for C language 1.2.2
+	REEC 1.2.2
+	(C)TOK Jelo Wang

+	Regular Engine is a free software created by (c) Techniques of Knowledge since 20090528,	
+	you can redistribute it and/or modifyit under the terms of the gnu general public license	
+	as published by the free software foundation, either version 3 of the license or any later 	
+	version.this program is distributed in the hope	that it will be useful,but without any 		
+	warranty.without even the implied warranty of merchantability or fitness for a particular 	
+	purpose.																					
+																													
+	(c) 	Techniques of Knowledge 
+		an open source group since 2008	
+		page : http://www.tok.cc
+		email : wqw85@sina.com
+
*/

#include "rex.h"

RegularExpressionsAtom regular_expressions_atom ;
RegularExpressionsAtom* regular_expressions_atom_walker;
RegularExpressionsAtom* new_rex_aotm_node;
RegularExpressionsAtom* current_regular_expressions_atom;

REECMONITOR reecmonitor = { RS_LEVEL_1 } ;
REXNESTED_FROM rex_nested_form = { 0 , 0 , 0 } ;

STRING regular_expressions = { 0 , 0 , 0 } ;
STRING object_string = { 0 , 0 , 0 } ;
STRING pattern_elements_matched = { 0 , 0 , 0 } ;
int regular_pattern_matched = 0;


void ReecNestedFormNewAtom ( REXNESTED_FROM* nested_form ) {

	//	author : Jelo Wang
	//	since : 20100330

	REXNESTED_FROM* form = 0 ;

	if ( !nested_form ) return ;

	form = (REXNESTED_FROM* ) MALLOC ( sizeof(REXNESTED_FROM) ) ;

	if ( !form ) return ;

	form->atom = (REXNESTED_ATOM* ) MALLOC ( sizeof(REXNESTED_ATOM) ) ;

	if ( !form->atom ) {
		FREE(form) ;
		return ;
	}

	form->atom->rea_head = 0 ;
	form->atom->rea_next = 0 ;

	form->nested_head = 0 ;
	form->nested_next = 0 ;

	if ( 0 == nested_form->nested_head ) {
		nested_form->nested_head = form ;
		nested_form->nested_next = form ;
	} else {
		nested_form->nested_next->nested_next = form ;
		nested_form->nested_next = form ;
	}

	nested_form->totall_nest ++ ;

}

void ReecNestedFormAtomAddHandle ( REXNESTED_FROM* nested_form , RegularExpressionsAtom* handle ) {

	//	author : Jelo Wang
	//	since : 20100330

	if ( 0 == handle ) return ;
	if ( 0 == nested_form ) return ; 
	if ( 0 == nested_form->totall_nest ) return ;
	if ( 0 == nested_form->nested_next ) return ; 
	if ( 0 == nested_form->nested_next->atom ) return ;

	if ( 0 == nested_form->nested_next->atom->rea_head ) {
		nested_form->nested_next->atom->rea_head = handle ;
		nested_form->nested_next->atom->rea_next = handle ;
	} else {
		nested_form->nested_next->atom->rea_next->next = handle ;
		nested_form->nested_next->atom->rea_next = handle ;
		nested_form->nested_next->atom->rea_next->next = 0 ;
	}


}


void ReecNestedFormAtomDestroy ( REXNESTED_FROM* nested_form ) {

	//	author : Jelo Wang
	//	since : 20100331

	REXNESTED_FROM* form_walker = 0 ;
	RegularExpressionsAtom* rex_atom_walker = 0 ;
	
	if ( !nested_form ) return ;

	for ( form_walker = nested_form->nested_head ; form_walker ; ) {
		
		for ( rex_atom_walker = form_walker->atom->rea_head ; rex_atom_walker ; ) {
			form_walker->atom->rea_next = rex_atom_walker->next ;
			if (rex_atom_walker->pattern_token_length)
				FREE(rex_atom_walker->pattern_token) ;			
			FREE(rex_atom_walker);
			rex_atom_walker = form_walker->atom->rea_next ;
		}

		nested_form->nested_next = form_walker->nested_next ;
		FREE(rex_atom_walker);
		FREE(form_walker);
		form_walker = nested_form->nested_next ;		
	}
  
	nested_form->nested_head = 0 ;
	nested_form->nested_next = 0 ;
	nested_form->totall_nest = 0 ;

	
}


void _regular_expressions_atom_table_initialize () {

	//	author : Jelo Wang
	//	(C)TOK
	
	regular_expressions_atom.next = 0;
	regular_expressions_atom.front = 0;
	regular_expressions_atom_walker = &regular_expressions_atom;

}
void _regular_expressions_atom_walker_initialize () {

	//	author : Jelo Wang
	//	(C)TOK
	
	regular_expressions_atom_walker = regular_expressions_atom.next ;
	current_regular_expressions_atom = regular_expressions_atom_walker ;

}


int _regular_expressions_atom_add_node( int type ,char* token , int times , int max_times ) {

	//	author : Jelo Wang
	//	(C)TOK
	
	int length = strlen(token);

	new_rex_aotm_node = (RegularExpressionsAtom* ) MALLOC ( sizeof(RegularExpressionsAtom) );

	if(!new_rex_aotm_node) {
		PRINT("FATAL ERROR : _regular_expressions_atom_add_node not enough memory!\n");
		return 0;
	}

	new_rex_aotm_node -> pattern_type = type;

	if(length) {

		new_rex_aotm_node -> pattern_token = (char* ) MALLOC ( length + 1 );

		if(!new_rex_aotm_node -> pattern_token) {
			PRINT("FATAL ERROR : _regular_expressions_atom_add_node not enough memory!\n");
			return 0;
		}

		strcpy(new_rex_aotm_node -> pattern_token,token);
		new_rex_aotm_node -> pattern_token_length = length;

	} else new_rex_aotm_node -> pattern_token_length = 0;

	new_rex_aotm_node -> next = 0;
	if ( 0 == rex_nested_form.totall_nest ) new_rex_aotm_node -> front = regular_expressions_atom_walker;
	new_rex_aotm_node -> pattern_times = times;
	new_rex_aotm_node -> pattern_max_times = max_times;
	new_rex_aotm_node -> pattern_matched_times = 0 ;
	new_rex_aotm_node -> operation = 0;

	if ( 0 == rex_nested_form.totall_nest ) {
		regular_expressions_atom_walker -> next = new_rex_aotm_node;
		regular_expressions_atom_walker = new_rex_aotm_node;
	} else {
		regular_expressions_atom_walker = new_rex_aotm_node;
		new_rex_aotm_node->front = 0 ;
		new_rex_aotm_node->next = 0 ;
	}

	regular_expressions_atom.totallatom ++ ;
	
}


void _regular_expressions_atom_table_destroy () {

	//	author : Jelo Wang
	//	(C)TOK
	
	_regular_expressions_atom_walker_initialize () ;

	while(regular_expressions_atom_walker){

		regular_expressions_atom.next = regular_expressions_atom_walker -> next;
		
		if(0 <regular_expressions_atom_walker->pattern_token_length) {
			if (regular_expressions_atom_walker->pattern_token)
				FREE((regular_expressions_atom_walker->pattern_token));
		}

		FREE(regular_expressions_atom_walker);
		regular_expressions_atom_walker = regular_expressions_atom.next;

	}

	REECMEMSET ( &regular_expressions_atom , 0 ,sizeof(RegularExpressionsAtom) ) ;

}



void _string_initialize ( STRING* string , char* ddata ) {

	//	author : Jelo Wang
	//	(C)TOK
	
	string->length = strlen(ddata);
	string->data = (char* ) MALLOC ( string->length + 1 );

	if(!string->data) {
		PRINT("FATAL ERROR : _string_initialize not enough memory!\n");
	} else {
		strcpy( string->data , ddata );
		string->walker = 0;
	}

}

void _string_initialize_with_length ( STRING* string , int llength ) {

	//	author : Jelo Wang
	//	(C)TOK
	
	string->length = llength;
	string->data = (char* ) MALLOC ( string->length + 1 );
	if(!string->data) 
		PRINT("FATAL ERROR : _string_initialize_with_length not enough memory!\n");
	string->walker = 0;

}

void _string_add( STRING* string , char element ) {

	//	author : Jelo Wang
	//	(C)TOK
	
	if( string->walker != string->length){

		string->data [ string->walker ] = element ;
		string->walker ++ ;

	}

}

char _string_get( STRING string ) {

	//	author : Jelo Wang
	//	(C)TOK
	
	if ( _string_overflowed (string) ) return 0 ;
	return string . data[ string . walker ];
}

int _string_overflowed( STRING string ) {

	//	author : Jelo Wang
	//	(C)TOK
	
	return ( string . walker >= string . length ) ? (1) : (0);

}

void _string_next( STRING* string ) {

	//	author : Jelo Wang
	//	(C)TOK
	
	string->walker ++ ;
}

void _string_destroy( STRING* string ) {

	//	author : Jelo Wang
	//	(C)TOK
	
	if ( string->data ) {
		FREE(string->data); 
		string->length = 0; 
		string->walker = 0; 
		string->data = 0 ;
	}

}

char _string_look( STRING string , int step ) {

	//	author : Jelo Wang
	//	(C)TOK
	
	if(step >= string . length)
		return 0;

	if((step + string . walker) >= string . length)
		return 0;

	return string . data [ step + string . walker ];

}

void _string_walker_add ( STRING* string , int step ) {

	//	author : Jelo Wang
	//	(C)TOK
	
	string->walker = string->walker + step;

}

void _string_reset_walker_with_element ( STRING* string , char element ) {

	//	author : Jelo Wang
	//	(C)TOK
	
	for(;string->walker < string->length && string->data[string->walker] != element;string->walker ++);

}
void _string_add_token( STRING* string , char* token ) {

	//	author : Jelo Wang
	//	(C)TOK

	
	int walker;
	
	for(walker = 0;*(token+walker) && string->walker < string->length ;walker ++ , string->walker ++)
		string->data [ string->walker ] = *(token+walker);
	

}


//	edited : Jelo Wang
//	since : 20090918
//	pattern <(gtkings)^1><(.com)^1>
//	pattern token : asdfsdfgtkingsasfasfd.comsdaf
//	return : gtkings.com
//	as for matching the pattern above , we shouldnt reset the engine
//	#define __reset_engine_ \
//		regular_pattern_matched = 0;\
//		_regular_expressions_atom_walker_initialize;\
//		pattern_elements_matched . walker = 0;\

void __restart_engine_ () {

	//	author : Jelo Wang
	//	(C)TOK
	
	regular_pattern_matched = 0;
	_regular_expressions_atom_walker_initialize () ;
	pattern_elements_matched.walker = 0;

}

void __reset_engine_ () {

	//	author : Jelo Wang
	//	(C)TOK
	
	regular_pattern_matched = 0;
	
}

