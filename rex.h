
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

#include "reio.h"
#include "string.h"

#define MALLOC(size) reec_malloc(size)
#define FREE(buffer) recc_free(buffer)

#define PRINT

#define __REEC_DEBUG__
#ifdef __REEC_DEBUG__
#define _PRINT_S(S) PRINT("%s",S);
#define _PRINT_I(I) PRINT("%d",I);
#else
#define _PRINT_S(S)
#define _PRINT_I(I)
#endif

#define smart_alpha(x) ('a' <= x && x <= 'z')
#define strong_alpha(x) ('A' <= x && x <= 'Z')
#define digit(x) ('0' <= x && x <= '9')

enum _alpha_ {
	_smart_ = 1,
	_strong_ = 2,
} ;

enum _regular_expression_ {
	
	//author:Jelo Wang
	//since : 20090528

	 __match_smart_alpha_normal_limit_pattern_,							//<(a-z)^1>
	 __match_smart_alpha_normal_none_limit_pattern_,					//<(a-z)^*>
	 __match_smart_alpha_scale_limit_pattern_,							//<(a-z){1,1}>
	 __match_smart_alpha_scale_none_limit_pattern_,						//<(a-z){1,*}>

	 __match_strong_alpha_normal_limit_pattern_,						//<(A-Z)^1>
	 __match_strong_alpha_normal_none_limit_pattern_,					//<(A-Z)^*>
	 __match_strong_alpha_scale_limit_pattern_,							//<(A-Z){1,1}>
	 __match_strong_alpha_scale_none_limit_pattern_,					//<(A-Z){1,*}>

	 __match_Both_Smart_Strong_alpha_normal_limit_pattern_,				//<(a-zA-Z)^1>
	 __match_Both_Smart_Strong_alpha_normal_none_limit_pattern_,		//<(a-zA-Z)^*>
	 __match_Both_Smart_Strong_alpha_scale_limit_pattern_,				//<(a-zA-Z){1,1}>
	 __match_Both_Smart_Strong_alpha_scale_none_limit_pattern_,			//<(a-zA-Z){1,*}>

	 __match_digit_normal_limit_pattern_,								//<(0-9)^1>
	 __match_digit_normal_none_limit_pattern_,							//<(0-9)^*>
	 __match_digit_scale_limit_pattern_,								//<(0-9){1,1}>
	 __match_digit_scale_none_limit_pattern_,							//<(0-9){1,*}>

	 __match_symbol_normal_limit_pattern_,								//<(symbol)^1>
	 __match_symbol_normal_none_limit_pattern_,							//<(symbol)^*>
	 __match_symbol_scale_limit_pattern_,								//<(symbol){1,1}>
	 __match_symbol_scale_none_limit_pattern_,							//<(symbol){1,*}>
		
	 __match_all_symbols_normal_limit_pattern_,							//<(*)^1>
	 __match_all_symbols_normal_none_limit_pattern_,					//<(*)^*>
	 __match_all_symbols_scale_limit_pattern_,							//<(*){1,1}>
	 __match_all_symbols_scale_none_limit_pattern_,						//<(*){1,*}>

	 __match_digit_alpha_normal_limit_pattern_,							//<(a-zA-Z0-9)^1>
	 __match_digit_alpha_normal_none_limit_pattern_,					//<(a-zA-Z0-9)^*>
	 __match_digit_alpha_scale_limit_pattern_,							//<(a-zA-Z0-9){1,1}>
	 __match_digit_alpha_scale_none_limit_pattern_,						//<(a-zA-Z0-9){1,*}>

	 __match_digit_smart_alpha_normal_limit_pattern_,					//<(a-z0-9)^1>
	 __match_digit_smart_alpha_normal_none_limit_pattern_,				//<(a-z0-9)^*>
	 __match_digit_smart_alpha_scale_limit_pattern_,					//<(a-z0-9){1,1}>
	 __match_digit_smart_alpha_scale_none_limit_pattern_,				//<(a-z0-9){1,*}>

	 __match_digit_strong_alpha_normal_limit_pattern_,					//<(A-Z0-9)^1>
	 __match_digit_strong_alpha_normal_none_limit_pattern_,				//<(A-Z0-9)^*>
	 __match_digit_strong_alpha_scale_limit_pattern_,					//<(A-Z0-9){1,1}>
	 __match_digit_strong_alpha_scale_none_limit_pattern_,				//<(A-Z0-9){1,*}>

	 __match_custom_pattern,											//...

} ;

enum REEC_STRICT_LEVEL {

	//	author:Jelo Wang
	//	since : 20100330
	
	//	LEVE 0 , allow pattern of string flow can not be continuous
	RS_LEVEL_0 ,
	//	LEVE 1 , make pattern of string flow must be continuous
	RS_LEVEL_1 ,


} ;

enum _RegularExpressionsAtomOperation {

	//author: Jelo Wang
	//since : 20090529
	

	//there is one logical operation in the engine which is operation of regular expressions combination.
	//<(*){1,*}>|<(symbol)^1>

	_RegularExpressionsAtomOperationOr = 0xff

};

enum _RegularExpressionsAtomOperationPriority {

	//author:Jelo Wang
	//since : 20090529
	//(c)TOK

	//operation flows like <(*){1,*}>|<(symbol)^1> in that expressions the computing priority of <(symbol)^1> is hight than <(*){1,*}>
	//these flows has '*' has the lowest computing priority _RegularExpressionsAtomOperationLow
	//others have the middle priority _RegularExpressionsAtomOperationMiddle

	_RegularExpressionsAtomOperationLow,
	_RegularExpressionsAtomOperationMiddle,
	_RegularExpressionsAtomOperationHigh,

};

enum RegularExpressionsAtom_Times {
	
	//author:Jelo Wang
	//since : 20090529

	_normal_limit = 30,
	_normal_none_limit,
	_scale_limit,
	_scale_none_limit,

};

typedef struct REECMONI {
	
	//	author: Jelo Wang
	//	since : 20100330
	
	//	(1) REEC_STRICT_LEVEL
	//	(2) nested form

	int rs_level ;

} REECMONITOR ;

typedef struct REXAOTM {

	//author:Jelo Wang
	//since : 20090528

	//a regular expression contents two elements <matching token,condition> we call it as lexical atom
	//'matching token' is the symbol that matching needed and the condition is a repeated times usually

	int totallatom ;
	
	int pattern_type;
	char* pattern_token;
	int pattern_token_length;
	int pattern_times;
	int pattern_max_times;
	int pattern_matched_times ;
// 	int recursive_times;
//	int recursive_max_times;
//	int recursive_type;
//	int recursive_expression;
//	int global_operation;
	int expression_scope;
	int priority_operation;
	int priority;
	int operation;
	struct REXAOTM* front;
	struct REXAOTM* next;

} RegularExpressionsAtom ;


typedef struct {

	//	author: Jelo Wang
	//	since : 20100330

	RegularExpressionsAtom* rea_head ; 
	RegularExpressionsAtom* rea_next ;

} REXNESTED_ATOM ;

typedef struct REXNESTED_FROMN {

	//	author: Jelo Wang
	//	since : 20100330

	int totall_nest ;

	REXNESTED_ATOM* atom ;
	struct REXNESTED_FROMN* nested_head ;
	struct REXNESTED_FROMN* nested_next ; 

} REXNESTED_FROM ;

typedef struct {

	//author:Jelo Wang
	//since : 20090528

	char* data;
	int length;
	int walker;

} STRING ;

extern RegularExpressionsAtom regular_expressions_atom ;
extern RegularExpressionsAtom* regular_expressions_atom_walker;
extern RegularExpressionsAtom* new_rex_aotm_node;
extern RegularExpressionsAtom* current_regular_expressions_atom;
extern REECMONITOR reecmonitor ;
extern REXNESTED_FROM rex_nested_form ;
extern int regular_pattern_matched ;

extern STRING regular_expressions ;
extern STRING object_string ;
extern STRING pattern_elements_matched ;

extern void ReecNestedFormNewAtom ( REXNESTED_FROM* nested_form ) ;
extern void ReecNestedFormAtomAddHandle ( REXNESTED_FROM* nested_form , RegularExpressionsAtom* handle ) ;
extern void _regular_expressions_atom_table_initialize () ;
extern void _regular_expressions_atom_walker_initialize () ;
extern int _regular_expressions_atom_add_node( int type ,char* token , int times , int max_times ) ;
extern void _regular_expressions_atom_table_destroy () ;
extern void _string_initialize ( STRING* string , char* ddata ) ;
extern void _string_initialize_with_length ( STRING* string , int llength ) ;
extern void _string_add( STRING* string , char element ) ;
extern char _string_get( STRING string ) ;
extern int _string_overflowed( STRING string ) ;
extern void _string_next( STRING* string ) ;
extern void _string_destroy( STRING* string ) ;
extern char _string_look( STRING string , int step ) ;
extern void _string_walker_add ( STRING* string , int step ) ;
extern void _string_reset_walker_with_element ( STRING* string , char element ) ;
extern void _string_add_token( STRING* string , char* token ) ;
extern void __restart_engine_ () ;
extern void __reset_engine_ () ;

