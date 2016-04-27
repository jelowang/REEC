
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

# define REEC_BENCHMARK
# ifdef REEC_BENCHMARK
# include <time.h>
# endif

int match_alpha_normal_limit_pattern( int alpha ) { 
	
	//	author: Jelo Wang
	//	since : 20090528
	//	(C)TOK
	
	int times = 0 ;

	while ( 0 == _string_overflowed( object_string ) ) {
		
		if (_smart_ == alpha) {

			if (smart_alpha(_string_get(object_string)) && times != current_regular_expressions_atom -> pattern_times ) {
			
				_string_add( &pattern_elements_matched , _string_get(object_string)) ;

				_string_next( &object_string ) ;
				current_regular_expressions_atom -> pattern_matched_times ++ ;
				times ++ ;
			
			} else if ( times == current_regular_expressions_atom -> pattern_times ) {
				return 1 ;
			} else if ( 0 < times ) {
				if ( RS_LEVEL_1 == reecmonitor.rs_level )
					return 0 ;		
				_string_next( &object_string ) ;
			} else if ( !_string_overflowed( object_string ) ) {
				if ( RS_LEVEL_1 == reecmonitor.rs_level )
					return 0 ;					
				_string_next( &object_string ) ;
			} else
				return 0 ;

		} else if (_strong_ == alpha) {
			
			if (strong_alpha(_string_get(object_string)) && times != current_regular_expressions_atom -> pattern_times ) {
			
				_string_add( &pattern_elements_matched , _string_get(object_string)) ;

				_string_next( &object_string ) ;
				current_regular_expressions_atom -> pattern_matched_times ++ ;
				times ++ ;
			
			} else if ( times == current_regular_expressions_atom -> pattern_times ) {
				return 1 ;
			} else if ( 0 < times ) {
				if ( RS_LEVEL_1 == reecmonitor.rs_level )
					return 0 ;		
				_string_next( &object_string ) ;
			} else if ( !_string_overflowed( object_string ) ) {
				if ( RS_LEVEL_1 == reecmonitor.rs_level )
					return 0 ;					
				_string_next( &object_string ) ;
			} else
				return 0 ;


		} else {

			if ((smart_alpha(_string_get(object_string)) || strong_alpha(_string_get(object_string))) && times != current_regular_expressions_atom -> pattern_times ) {

				_string_add( &pattern_elements_matched , _string_get(object_string)) ;

				_string_next( &object_string ) ;
				current_regular_expressions_atom -> pattern_matched_times ++ ;
				times ++ ;
			
			} else if ( times == current_regular_expressions_atom -> pattern_times ) {
				return 1 ;
			} else if ( 0 < times ) {
				if ( RS_LEVEL_1 == reecmonitor.rs_level )
					return 0 ;		
				_string_next( &object_string ) ;
			} else if ( !_string_overflowed( object_string ) ) {
				if ( RS_LEVEL_1 == reecmonitor.rs_level )
					return 0 ;					
				_string_next( &object_string ) ;
			} else
				return 0 ;


		}
		
	}
	
	return ( times == current_regular_expressions_atom -> pattern_times )  ? 1 : 0 ;


}				

int match_alpha_none_limit_pattern ( int alpha )	{ 
	
	//	author: Jelo Wang
	//	since : 20090528
	//	(C)TOK	

	int times = 0 ;

	while ( !_string_overflowed( object_string ) ) {
		
		if (_smart_ == alpha) {

			if (smart_alpha(_string_get(object_string))) {
			
				_string_add( &pattern_elements_matched , _string_get(object_string)) ;

				_string_next( &object_string ) ;
				times ++ ;
			
			} else if ( !_string_overflowed( object_string )  ) {	
				if ( 0 == times && RS_LEVEL_1 == reecmonitor.rs_level )
					return 0 ;	
				else if ( 0 < times && RS_LEVEL_1 == reecmonitor.rs_level )
					return 1 ;		
				_string_next( &object_string ) ;
			} else if (times) {
				return 1 ;
			} else
				return 0 ;

		} else if (_strong_ == alpha) {

			if (strong_alpha(_string_get(object_string))) {
			
				_string_add( &pattern_elements_matched , _string_get(object_string)) ;

				_string_next( &object_string ) ;
				times ++ ;
			
			} else if ( !_string_overflowed( object_string )  ) {
				if ( 0 == times && RS_LEVEL_1 == reecmonitor.rs_level )
					return 0 ;	
				else if ( 0 < times && RS_LEVEL_1 == reecmonitor.rs_level )
					return 1 ;		
				_string_next( &object_string ) ;
			} else if (times) {
				return 1 ;
			} else
				return 0 ;



		} else {

			if (smart_alpha(_string_get(object_string)) || strong_alpha(_string_get(object_string))) {
			
				_string_add( &pattern_elements_matched , _string_get(object_string)) ;

				_string_next( &object_string ) ;
				times ++ ;
			
			} else if ( !_string_overflowed( object_string )  ) {

				if ( 0 == times && RS_LEVEL_1 == reecmonitor.rs_level )
					return 0 ;	
				else if ( 0 < times && RS_LEVEL_1 == reecmonitor.rs_level )
					return 1 ;
				
				_string_next( &object_string ) ;
			} else if (times) {
				return 1 ;
			} else
				return 0 ;



		}

	}
	
	return times  ? 1 : 0 ;

}	
	
int match_alpha_scale_limit_pattern ( int alpha ) { 
	
	//	author: Jelo Wang
	//	since : 20090528
	//	(C)TOK	
	
	int times = 0 ;

	while ( !_string_overflowed( object_string ) ) {
	
		if ( _smart_ == alpha ) {

			if (smart_alpha(_string_get(object_string))) {
			
				_string_add( &pattern_elements_matched , _string_get(object_string)) ;

				_string_next( &object_string ) ;
				times ++ ;

				if (times == current_regular_expressions_atom -> pattern_max_times )
					break ;
			
			} else if ( !_string_overflowed( object_string )  ) {
				if ( 0 == times && RS_LEVEL_1 == reecmonitor.rs_level )
					return 0 ;	
				else if ( current_regular_expressions_atom -> pattern_times > times && RS_LEVEL_1 == reecmonitor.rs_level ) 
					return 0 ;
				else if ( current_regular_expressions_atom -> pattern_times <= times && RS_LEVEL_1 == reecmonitor.rs_level ) 
					return 1 ;				
				_string_next( &object_string ) ;
			} else if ( current_regular_expressions_atom -> pattern_times <= times && times <= current_regular_expressions_atom -> pattern_max_times ) {
				return 1 ;
			} else
				return 0 ;

		} else if ( _strong_ == alpha ) {

			if (strong_alpha(_string_get(object_string))) {
			
				_string_add( &pattern_elements_matched , _string_get(object_string)) ;

				_string_next( &object_string ) ;
				times ++ ;

				if (times == current_regular_expressions_atom -> pattern_max_times )
					break ;
	
			} else if ( !_string_overflowed( object_string )  ) {
				if ( 0 == times && RS_LEVEL_1 == reecmonitor.rs_level )
					return 0 ;	
				else if ( current_regular_expressions_atom -> pattern_times > times && RS_LEVEL_1 == reecmonitor.rs_level ) 
					return 0 ;
				else if ( current_regular_expressions_atom -> pattern_times <= times && RS_LEVEL_1 == reecmonitor.rs_level ) 
					return 1 ;	
				_string_next( &object_string ) ;
			} else if ( current_regular_expressions_atom -> pattern_times <= times && times <= current_regular_expressions_atom -> pattern_max_times ) {
				return 1 ;
			} else
				return 0 ;



		} else {

			if ( smart_alpha(_string_get(object_string)) || strong_alpha(_string_get(object_string)) ) {
			
				_string_add( &pattern_elements_matched , _string_get(object_string)) ;

				_string_next( &object_string ) ;
				times ++ ;

				if (times == current_regular_expressions_atom -> pattern_max_times )
					break ;
			
			} else if ( !_string_overflowed( object_string )  ) {
				if ( 0 == times && RS_LEVEL_1 == reecmonitor.rs_level )
					return 0 ;	
				else if ( current_regular_expressions_atom -> pattern_times > times && RS_LEVEL_1 == reecmonitor.rs_level ) 
					return 0 ;
				else if ( current_regular_expressions_atom -> pattern_times <= times && RS_LEVEL_1 == reecmonitor.rs_level ) 
					return 1 ;	
				_string_next( &object_string ) ;
			} else if ( current_regular_expressions_atom -> pattern_times <= times && times <= current_regular_expressions_atom -> pattern_max_times ) {
				return 1 ;
			} else
				return 0 ;	



		}

	}
	
	return (current_regular_expressions_atom -> pattern_times  <= times && times <= current_regular_expressions_atom -> pattern_max_times )  ? 1 : 0 ;

}		

int match_alpha_scale_none_limit_pattern ( int alpha ) { 
	
	//	author: Jelo Wang
	//	since : 20090528
	//	(C)TOK	

	int times = 0 ;

	while ( !_string_overflowed( object_string ) ) {
	
		if ( _smart_ == alpha ) {
			if (smart_alpha(_string_get(object_string))) {
			
				_string_add( &pattern_elements_matched , _string_get(object_string)) ;
				
				_string_next( &object_string ) ;
				times ++ ;
			
			} else if ( !_string_overflowed( object_string )  ) {
				if ( 0 == times && RS_LEVEL_1 == reecmonitor.rs_level )
					return 0 ;	
				else if ( current_regular_expressions_atom -> pattern_times > times && RS_LEVEL_1 == reecmonitor.rs_level ) 
					return 0 ;
				else if ( current_regular_expressions_atom -> pattern_times <= times && RS_LEVEL_1 == reecmonitor.rs_level ) 
					return 1 ;	
				_string_next( &object_string ) ;
			} else if ( current_regular_expressions_atom -> pattern_times <= times ) {
				return 1 ;
			} else
				return 0 ;	

		
		} else if ( _strong_ == alpha ) {
			if (strong_alpha(_string_get(object_string))) {

				_string_add( &pattern_elements_matched , _string_get(object_string)) ;
				
				_string_next( &object_string ) ;
				times ++ ;
			
			} else if ( !_string_overflowed( object_string )  ) {
				if ( 0 == times && RS_LEVEL_1 == reecmonitor.rs_level )
					return 0 ;	
				else if ( current_regular_expressions_atom -> pattern_times > times && RS_LEVEL_1 == reecmonitor.rs_level ) 
					return 0 ;
				else if ( current_regular_expressions_atom -> pattern_times <= times && RS_LEVEL_1 == reecmonitor.rs_level ) 
					return 1 ;	
				_string_next( &object_string ) ;
			} else if ( current_regular_expressions_atom -> pattern_times <= times ) {
				return 1 ;
			} else
				return 0 ;	


		} else {
			if ( smart_alpha(_string_get(object_string)) || strong_alpha(_string_get(object_string)) ) {
			
				_string_add( &pattern_elements_matched , _string_get(object_string)) ;
				
				_string_next( &object_string ) ;
				times ++ ;
			
			} else if ( !_string_overflowed( object_string )  ) {
				if ( 0 == times && RS_LEVEL_1 == reecmonitor.rs_level )
					return 0 ;	
				else if ( current_regular_expressions_atom -> pattern_times > times && RS_LEVEL_1 == reecmonitor.rs_level ) 
					return 0 ;
				else if ( current_regular_expressions_atom -> pattern_times <= times && RS_LEVEL_1 == reecmonitor.rs_level ) 
					return 1 ;	
				_string_next( &object_string ) ;
			} else if ( current_regular_expressions_atom -> pattern_times <= times ) {
				return 1 ;
			} else
				return 0 ;	

		}

	}

	return ( current_regular_expressions_atom -> pattern_times  <= times )  ? 1 : 0 ;

}

int match_digit_pattern( int type ) {
	
	//	author: Jelo Wang
	//	since : 20090528
	//	(C)TOK	

	int times = 0 ;

	while ( 0 == _string_overflowed( object_string ) ) {
		
		if (__match_digit_normal_limit_pattern_ == type) {

			if (digit(_string_get(object_string)) && times != current_regular_expressions_atom -> pattern_times ) {
			
				_string_add( &pattern_elements_matched , _string_get(object_string)) ;

				_string_next( &object_string ) ;
				current_regular_expressions_atom -> pattern_matched_times ++ ;
				times ++ ;
			
			} else if ( times == current_regular_expressions_atom -> pattern_times ) {
				return 1 ;
			} else if ( !_string_overflowed( object_string ) ) {
				if ( RS_LEVEL_1 == reecmonitor.rs_level )
					return 0 ;		
				_string_next( &object_string ) ;
			} else
				return 0 ;

		} else if (__match_digit_normal_none_limit_pattern_ == type) {

			if (digit(_string_get(object_string))) {

				_string_add( &pattern_elements_matched , _string_get(object_string)) ;

				_string_next( &object_string ) ;
				times ++ ;
			
			} else if ( !_string_overflowed( object_string )  ) {
				if ( 0 == times && RS_LEVEL_1 == reecmonitor.rs_level )
					return 0 ;	
				else if ( 0 < times && RS_LEVEL_1 == reecmonitor.rs_level )
					return 1 ;			
				_string_next( &object_string ) ;
			} else if (times) {
				return 1 ;
			} else
				return 0 ;

		} else if (__match_digit_scale_limit_pattern_ == type) {

			if (digit(_string_get(object_string))) {

				_string_add( &pattern_elements_matched , _string_get(object_string)) ;

				_string_next( &object_string ) ;
				times ++ ;

				if (times == current_regular_expressions_atom -> pattern_max_times )
					break ;
			
			} else if ( !_string_overflowed( object_string )  ) {
				if ( 0 == times && RS_LEVEL_1 == reecmonitor.rs_level )
					return 0 ;	
				else if ( current_regular_expressions_atom -> pattern_times > times && RS_LEVEL_1 == reecmonitor.rs_level ) 
					return 0 ;
				else if ( current_regular_expressions_atom -> pattern_times <= times && RS_LEVEL_1 == reecmonitor.rs_level ) 
					return 1 ;				
				_string_next( &object_string ) ;
			} else if ( current_regular_expressions_atom -> pattern_times <= times && times <= current_regular_expressions_atom -> pattern_max_times ) {
				return 1 ;
			} else
				return 0 ;


		} else if (__match_digit_scale_none_limit_pattern_ == type) {
			
			if ( digit(_string_get(object_string)) ) {
			
				_string_add( &pattern_elements_matched , _string_get(object_string)) ;
				
				_string_next( &object_string ) ;
				times ++ ;
			
			} else if ( !_string_overflowed( object_string )  ) {
				if ( 0 == times && RS_LEVEL_1 == reecmonitor.rs_level )
					return 0 ;	
				else if ( current_regular_expressions_atom -> pattern_times > times && RS_LEVEL_1 == reecmonitor.rs_level ) 
					return 0 ;
				else if ( current_regular_expressions_atom -> pattern_times <= times && RS_LEVEL_1 == reecmonitor.rs_level ) 
					return 1 ;	
				_string_next( &object_string ) ;
			} else if ( current_regular_expressions_atom -> pattern_times <= times ) {
				return 1 ;
			} else
				return 0 ;	


		}
		
	}
	
	switch(type) {
		case __match_digit_normal_limit_pattern_:
			return ( times == current_regular_expressions_atom -> pattern_times ) ? 1 : 0 ;
		case __match_digit_normal_none_limit_pattern_:
			return times ? 1 : 0 ; 
		case __match_digit_scale_limit_pattern_:
			return (current_regular_expressions_atom -> pattern_times  <= times && times <= current_regular_expressions_atom -> pattern_max_times ) ? 1: 0 ;
		case __match_digit_scale_none_limit_pattern_:
			return ( current_regular_expressions_atom -> pattern_times  <= times ) ? 1 : 0 ;
	}

}

int match_symbol_pattern( int type ) {
	
	//	author: Jelo Wang
	//	since : 20090528
	//	(C)TOK	

	char* buffer = (char* ) MALLOC ( current_regular_expressions_atom -> pattern_token_length + 1 ) ;
	int buffer_walker = 0 ;
	int walker = 0 ;
	int walker_saver = 0 ;
	int times = 0 ;
	int global_walker_saver = object_string.walker ;

	if ( !buffer ) return 0  ;

	while ( 0 == _string_overflowed( object_string ) ) {

		if ( __match_symbol_normal_limit_pattern_ == type ) {
			
			walker_saver = object_string.walker ;

			for (walker = 0,buffer_walker = 0 ;walker < current_regular_expressions_atom -> pattern_token_length ;walker ++) {

				buffer [ buffer_walker ] = _string_get(object_string) ;
				_string_next(&object_string) ;
				buffer_walker ++ ;
			
			}
			
			buffer [ buffer_walker ] = '\0' ; 

			if (!strcmp(buffer,current_regular_expressions_atom->pattern_token)) {

				_string_add_token( &pattern_elements_matched , buffer) ;							
				times ++ ;
				current_regular_expressions_atom -> pattern_matched_times ++ ;

				if ( times == current_regular_expressions_atom -> pattern_times )
					break ;

			} else if ( times == current_regular_expressions_atom -> pattern_times ) {
				object_string.walker = walker_saver ;
				FREE(buffer) ;
				return 1 ;
			} else if ( !_string_overflowed( object_string ) ) {
				if ( RS_LEVEL_1 == reecmonitor.rs_level ) {
					object_string.walker = walker_saver ;
					FREE(buffer) ;
					return 0 ;		
				} 
				object_string.walker = walker_saver + 1 ;
			} else { 
				object_string.walker = walker_saver ;
				FREE(buffer) ;
				return 0 ; 
			}

		} else if (__match_symbol_normal_none_limit_pattern_ == type) {
			
			walker_saver = object_string.walker ;

			for (walker = 0,buffer_walker = 0 ;walker < current_regular_expressions_atom -> pattern_token_length ;walker ++) {
					
				buffer [ buffer_walker ] = _string_get(object_string) ;
				_string_next(&object_string) ;
				buffer_walker ++ ;

			}
		
			buffer [ buffer_walker ] = '\0' ; 			

			if (!strcmp(buffer,current_regular_expressions_atom->pattern_token)) {

				_string_add_token( &pattern_elements_matched , buffer) ;
				times ++ ;

			} else if ( !_string_overflowed( object_string )  ) {
				if ( 0 == times && RS_LEVEL_1 == reecmonitor.rs_level ) {
					object_string.walker = walker_saver ;
					FREE(buffer) ;
					return 0 ;	
				} else if ( 0 < times && RS_LEVEL_1 == reecmonitor.rs_level ) {
					object_string.walker = walker_saver ;
					FREE(buffer) ;
					return 1 ;			
				}
				object_string.walker = walker_saver + 1 ;
			} else if (times) {
				object_string.walker = walker_saver ;
				FREE(buffer) ;
				return 1 ;
			} else { 
				object_string.walker = walker_saver ;
				FREE(buffer) ;
				return 0 ; 
			}

		} else if (__match_symbol_scale_limit_pattern_ == type) {

			walker_saver = object_string.walker ;

			for (walker = 0,buffer_walker = 0 ;walker < current_regular_expressions_atom -> pattern_token_length ;walker ++) {
					
				buffer [ buffer_walker ] = _string_get(object_string) ;
				_string_next(&object_string) ;
				buffer_walker ++ ;

			}
		
			buffer [ buffer_walker ] = '\0' ; 			

			if (!strcmp(buffer,current_regular_expressions_atom->pattern_token)) {

				_string_add_token( &pattern_elements_matched , buffer) ;
				times ++ ;
				
				if (times == current_regular_expressions_atom -> pattern_max_times )
					break ;
				
			} else if ( !_string_overflowed( object_string )  ) {
				if ( 0 == times && RS_LEVEL_1 == reecmonitor.rs_level ) {
					object_string.walker = walker_saver ;
					FREE(buffer) ;				
					return 0 ;	
				} else if ( current_regular_expressions_atom -> pattern_times > times && RS_LEVEL_1 == reecmonitor.rs_level ) {
					object_string.walker = walker_saver ;
					FREE(buffer) ;					
					return 0 ;
				} else if ( current_regular_expressions_atom -> pattern_times <= times && RS_LEVEL_1 == reecmonitor.rs_level ) { 
					object_string.walker = walker_saver ;
					FREE(buffer) ;					
					return 1 ;				
				}
				object_string.walker = walker_saver + 1 ;
			} else if ( current_regular_expressions_atom -> pattern_times <= times && times <= current_regular_expressions_atom -> pattern_max_times ) {
				object_string.walker = walker_saver ;
				FREE(buffer) ;
				return 1 ;
			} else {
				object_string.walker = walker_saver ;
				FREE(buffer) ;
				return 0 ; 		
			}
			
		} else if (__match_symbol_scale_none_limit_pattern_ == type) {

			walker_saver = object_string.walker ;

			for (walker = 0,buffer_walker = 0 ;walker < current_regular_expressions_atom -> pattern_token_length ;walker ++) {
					
				buffer [ buffer_walker ] = _string_get(object_string) ;
				_string_next(&object_string) ;
				buffer_walker ++ ;

			}
		
			buffer [ buffer_walker ] = '\0' ; 			
	
			if ( !strcmp(buffer,current_regular_expressions_atom->pattern_token)) {
			
				_string_add_token( &pattern_elements_matched , buffer) ;
				times ++ ;
				
			} else if ( !_string_overflowed( object_string )  ) {
				if ( 0 == times && RS_LEVEL_1 == reecmonitor.rs_level ) {
					object_string.walker = walker_saver ;
					FREE(buffer) ;				
					return 0 ;	
				} else if ( current_regular_expressions_atom -> pattern_times > times && RS_LEVEL_1 == reecmonitor.rs_level ) {
					object_string.walker = walker_saver ;
					FREE(buffer) ;					
					return 0 ;
				} else if ( current_regular_expressions_atom -> pattern_times <= times && RS_LEVEL_1 == reecmonitor.rs_level ) { 
					object_string.walker = walker_saver ;
					FREE(buffer) ;					
					return 1 ;				
				}
				object_string.walker = walker_saver + 1 ;
			} else if ( current_regular_expressions_atom -> pattern_times <= times ) {
				object_string.walker = walker_saver ;
				FREE(buffer) ;
				return 1 ;
			} else {
				object_string.walker = walker_saver ;
				FREE(buffer) ;
				return 0 ;		
			}

		}

	}

	FREE(buffer) ;

	switch(type) {
		case __match_symbol_normal_limit_pattern_:
			return ( times == current_regular_expressions_atom -> pattern_times ) ? 1 : 0 ;
		case __match_symbol_normal_none_limit_pattern_:
			return times ? 1: 0 ;
		case __match_symbol_scale_limit_pattern_:
			return (current_regular_expressions_atom -> pattern_times  <= times && times <= current_regular_expressions_atom -> pattern_max_times ) ? 1 : 0 ;
		case __match_symbol_scale_none_limit_pattern_:
			return ( current_regular_expressions_atom -> pattern_times  <= times ) ? 1 : 0 ;
	}

}


int match_all_symbol_pattern( int type ) {

	//	author: Jelo Wang
	//	since : 20090529
	//	(C)TOK	

	int times = 0 ;

	while ( 0 == _string_overflowed( object_string ) ) {
		
		if (__match_all_symbols_normal_limit_pattern_ == type) {

			if (times != current_regular_expressions_atom -> pattern_times ) {
			
				_string_add( &pattern_elements_matched , _string_get(object_string)) ;

				_string_next( &object_string ) ;
				current_regular_expressions_atom -> pattern_matched_times ++ ;
				times ++ ;
			
			} else if ( times == current_regular_expressions_atom -> pattern_times ) {
				return 1 ;
			}

		} else if (__match_all_symbols_normal_none_limit_pattern_ == type) {

			_string_add( &pattern_elements_matched , _string_get(object_string)) ;
			
			_string_next( &object_string ) ;
			times ++ ;

		} else if (__match_all_symbols_scale_limit_pattern_ == type) {

			_string_add( &pattern_elements_matched , _string_get(object_string)) ;

			_string_next( &object_string ) ;
			times ++ ;

			if (times == current_regular_expressions_atom -> pattern_max_times )
				break ;

		} else if (__match_all_symbols_scale_none_limit_pattern_ == type) {
		
			_string_add( &pattern_elements_matched , _string_get(object_string)) ;
				
			_string_next( &object_string ) ;
			times ++ ;

		}
		
	}

	switch(type) {
		case __match_all_symbols_normal_limit_pattern_:
			return ( times == current_regular_expressions_atom -> pattern_times ) ? 1 : 0 ;
		case __match_all_symbols_normal_none_limit_pattern_:
			return (times) ? 1 : 0 ;
		case __match_all_symbols_scale_limit_pattern_:
			return ( current_regular_expressions_atom -> pattern_times  <= times && times <= current_regular_expressions_atom -> pattern_max_times ) ? 1 : 0 ;
		case __match_all_symbols_scale_none_limit_pattern_:
			return ( current_regular_expressions_atom -> pattern_times  <= times ) ? 1 : 0 ;
	}


}

int match_digit_alpha_pattern( int type ) {
	
	//	author: Jelo Wang
	//	since : 20090530
	//	(C)TOK	

	int times = 0 ;

	while ( 0 == _string_overflowed( object_string ) ) {
		
		if (__match_digit_alpha_normal_limit_pattern_ == type) {

			if ((digit(_string_get(object_string)) || smart_alpha(_string_get(object_string)) || strong_alpha(_string_get(object_string)) ) && times != current_regular_expressions_atom -> pattern_times ) {
			
				_string_add( &pattern_elements_matched , _string_get(object_string)) ;

				_string_next( &object_string ) ;
				current_regular_expressions_atom -> pattern_matched_times ++ ;
				times ++ ;
			
			} else if ( times == current_regular_expressions_atom -> pattern_times ) {
				return 1 ;
			} else if ( !_string_overflowed( object_string ) ) {
				if ( RS_LEVEL_1 == reecmonitor.rs_level )
					return 0 ;		
				_string_next( &object_string ) ;
			} else
				return 0 ;


		} else if (__match_digit_alpha_normal_none_limit_pattern_ == type) {

			if (digit(_string_get(object_string)) || smart_alpha(_string_get(object_string)) || strong_alpha(_string_get(object_string)) ) {

				_string_add( &pattern_elements_matched , _string_get(object_string)) ;

				_string_next( &object_string ) ;
				times ++ ;
			
			} else if ( !_string_overflowed( object_string )  ) {
				if ( 0 == times && RS_LEVEL_1 == reecmonitor.rs_level )
					return 0 ;	
				else if ( 0 < times && RS_LEVEL_1 == reecmonitor.rs_level )
					return 1 ;			
				_string_next( &object_string ) ;
			} else if (times) {
				return 1 ;
			} else
				return 0 ;


		} else if (__match_digit_alpha_scale_limit_pattern_ == type) {

			if ( digit(_string_get(object_string)) || smart_alpha(_string_get(object_string)) || strong_alpha(_string_get(object_string)) ) {

				_string_add( &pattern_elements_matched , _string_get(object_string)) ;

				_string_next( &object_string ) ;
				times ++ ;

				if (times == current_regular_expressions_atom -> pattern_max_times )
					break ;
			
			} else if ( !_string_overflowed( object_string )  ) {
				if ( 0 == times && RS_LEVEL_1 == reecmonitor.rs_level )
					return 0 ;	
				else if ( current_regular_expressions_atom -> pattern_times > times && RS_LEVEL_1 == reecmonitor.rs_level ) 
					return 0 ;
				else if ( current_regular_expressions_atom -> pattern_times <= times && RS_LEVEL_1 == reecmonitor.rs_level ) 
					return 1 ;				
				_string_next( &object_string ) ;
			} else if ( current_regular_expressions_atom -> pattern_times <= times && times <= current_regular_expressions_atom -> pattern_max_times ) {
				return 1 ;
			} else
				return 0 ;


		} else if (__match_digit_alpha_scale_none_limit_pattern_ == type) {
			
			if ( digit(_string_get(object_string)) || smart_alpha(_string_get(object_string)) || strong_alpha(_string_get(object_string)) ) {
			
				_string_add( &pattern_elements_matched , _string_get(object_string)) ;
				
				_string_next( &object_string ) ;
				times ++ ;
			
			} else if ( !_string_overflowed( object_string )  ) {
				if ( 0 == times && RS_LEVEL_1 == reecmonitor.rs_level )
					return 0 ;	
				else if ( current_regular_expressions_atom -> pattern_times > times && RS_LEVEL_1 == reecmonitor.rs_level ) 
					return 0 ;
				else if ( current_regular_expressions_atom -> pattern_times <= times && RS_LEVEL_1 == reecmonitor.rs_level ) 
					return 1 ;				
				_string_next( &object_string ) ;
			} else if ( current_regular_expressions_atom -> pattern_times <= times ) {
				return 1 ;
			} else
				return 0 ;


		} else if (__match_digit_smart_alpha_normal_limit_pattern_ == type) {

			if ( ( digit(_string_get(object_string)) || smart_alpha(_string_get(object_string)) ) && times != current_regular_expressions_atom -> pattern_times ) {
			
				_string_add( &pattern_elements_matched , _string_get(object_string)) ;

				_string_next( &object_string ) ;
				current_regular_expressions_atom -> pattern_matched_times ++ ;
				times ++ ;
			
			} else if ( times == current_regular_expressions_atom -> pattern_times ) {
				return 1 ;
			} else if ( !_string_overflowed( object_string ) ) {
				if ( RS_LEVEL_1 == reecmonitor.rs_level )
					return 0 ;		
				_string_next( &object_string ) ;
			} else
				return 0 ;


		} else if (__match_digit_smart_alpha_normal_none_limit_pattern_ == type) {

			if (digit(_string_get(object_string)) || smart_alpha(_string_get(object_string))) {

				_string_add( &pattern_elements_matched , _string_get(object_string)) ;

				_string_next( &object_string ) ;
				times ++ ;
			
			} else if ( !_string_overflowed( object_string )  ) {
				if ( 0 == times && RS_LEVEL_1 == reecmonitor.rs_level )
					return 0 ;	
				else if ( 0 < times && RS_LEVEL_1 == reecmonitor.rs_level )
					return 1 ;			
				_string_next( &object_string ) ;
			} else if (times) {
				return 1 ;
			} else
				return 0 ;


		} else if (__match_digit_smart_alpha_scale_limit_pattern_ == type) {

			if (digit(_string_get(object_string)) || smart_alpha(_string_get(object_string))) {

				_string_add( &pattern_elements_matched , _string_get(object_string)) ;

				_string_next( &object_string ) ;
				times ++ ;

				if (times == current_regular_expressions_atom -> pattern_max_times )
					break ;
			
			} else if ( !_string_overflowed( object_string )  ) {
				if ( 0 == times && RS_LEVEL_1 == reecmonitor.rs_level )
					return 0 ;	
				else if ( current_regular_expressions_atom -> pattern_times > times && RS_LEVEL_1 == reecmonitor.rs_level ) 
					return 0 ;
				else if ( current_regular_expressions_atom -> pattern_times <= times && RS_LEVEL_1 == reecmonitor.rs_level ) 
					return 1 ;				
				_string_next( &object_string ) ;
			} else if ( current_regular_expressions_atom -> pattern_times <= times && times <= current_regular_expressions_atom -> pattern_max_times ) {
				return 1 ;
			} else
				return 0 ;


		} else if (__match_digit_smart_alpha_scale_none_limit_pattern_ == type) {
			
			if ( digit(_string_get(object_string)) || smart_alpha(_string_get(object_string)) ) {
			
				_string_add( &pattern_elements_matched , _string_get(object_string)) ;
				
				_string_next( &object_string ) ;
				times ++ ;
			
			} else if ( !_string_overflowed( object_string )  ) {
				if ( 0 == times && RS_LEVEL_1 == reecmonitor.rs_level )
					return 0 ;	
				else if ( current_regular_expressions_atom -> pattern_times > times && RS_LEVEL_1 == reecmonitor.rs_level ) 
					return 0 ;
				else if ( current_regular_expressions_atom -> pattern_times <= times && RS_LEVEL_1 == reecmonitor.rs_level ) 
					return 1 ;				
				_string_next( &object_string ) ;
			} else if ( current_regular_expressions_atom -> pattern_times <= times ) {
				return 1 ;
			} else
				return 0 ;


		} else if (__match_digit_strong_alpha_normal_limit_pattern_ == type) {

			if (( digit(_string_get(object_string)) || strong_alpha(_string_get(object_string)) ) && times != current_regular_expressions_atom -> pattern_times ) {
			
				_string_add( &pattern_elements_matched , _string_get(object_string)) ;

				_string_next( &object_string ) ;
				current_regular_expressions_atom -> pattern_matched_times ++ ;
				times ++ ;
			
			} else if ( times == current_regular_expressions_atom -> pattern_times ) {
				return 1 ;
			} else if ( !_string_overflowed( object_string ) ) {
				if ( RS_LEVEL_1 == reecmonitor.rs_level )
					return 0 ;		
				_string_next( &object_string ) ;
			} else
				return 0 ;


		} else if (__match_digit_strong_alpha_normal_none_limit_pattern_ == type) {

			if (digit(_string_get(object_string)) || strong_alpha(_string_get(object_string))) {

				_string_add( &pattern_elements_matched , _string_get(object_string)) ;

				_string_next( &object_string ) ;
				times ++ ;
			
			} else if ( !_string_overflowed( object_string )  ) {
				if ( 0 == times && RS_LEVEL_1 == reecmonitor.rs_level )
					return 0 ;	
				else if ( 0 < times && RS_LEVEL_1 == reecmonitor.rs_level )
					return 1 ;			
				_string_next( &object_string ) ;
			} else if (times) {
				return 1 ;
			} else
				return 0 ;


		} else if (__match_digit_strong_alpha_scale_limit_pattern_ == type) {

			if (digit(_string_get(object_string)) || strong_alpha(_string_get(object_string))) {

				_string_add( &pattern_elements_matched , _string_get(object_string)) ;

				_string_next( &object_string ) ;
				times ++ ;

				if (times == current_regular_expressions_atom -> pattern_max_times )
					break ;
			
			} else if ( !_string_overflowed( object_string )  ) {
				if ( 0 == times && RS_LEVEL_1 == reecmonitor.rs_level )
					return 0 ;	
				else if ( current_regular_expressions_atom -> pattern_times > times && RS_LEVEL_1 == reecmonitor.rs_level ) 
					return 0 ;
				else if ( current_regular_expressions_atom -> pattern_times <= times && RS_LEVEL_1 == reecmonitor.rs_level ) 
					return 1 ;				
				_string_next( &object_string ) ;
			} else if ( current_regular_expressions_atom -> pattern_times <= times && times <= current_regular_expressions_atom -> pattern_max_times ) {
				return 1 ;
			} else
				return 0 ;

		} else if (__match_digit_strong_alpha_scale_none_limit_pattern_ == type) {
			
			if ( digit(_string_get(object_string)) || strong_alpha(_string_get(object_string)) ) {
			
				_string_add( &pattern_elements_matched , _string_get(object_string)) ;
				
				_string_next( &object_string ) ;
				times ++ ;
			
			} else if ( !_string_overflowed( object_string )  ) {
				if ( 0 == times && RS_LEVEL_1 == reecmonitor.rs_level )
					return 0 ;	
				else if ( current_regular_expressions_atom -> pattern_times > times && RS_LEVEL_1 == reecmonitor.rs_level ) 
					return 0 ;
				else if ( current_regular_expressions_atom -> pattern_times <= times && RS_LEVEL_1 == reecmonitor.rs_level ) 
					return 1 ;				
				_string_next( &object_string ) ;
			} else if ( current_regular_expressions_atom -> pattern_times <= times ) {
				return 1 ;
			} else
				return 0 ;


		}

	}
	
	switch(type) {

		case __match_digit_alpha_normal_limit_pattern_:
		case __match_digit_smart_alpha_normal_limit_pattern_:
		case __match_digit_strong_alpha_normal_limit_pattern_:
			return ( times == current_regular_expressions_atom -> pattern_times ) ? 1 : 0 ;

		case __match_digit_alpha_normal_none_limit_pattern_:
		case __match_digit_smart_alpha_normal_none_limit_pattern_:
		case __match_digit_strong_alpha_normal_none_limit_pattern_:
			return times ? 1 : 0 ; 

		case __match_digit_alpha_scale_limit_pattern_:
		case __match_digit_smart_alpha_scale_limit_pattern_:
		case __match_digit_strong_alpha_scale_limit_pattern_:
			return (current_regular_expressions_atom -> pattern_times  <= times && times <= current_regular_expressions_atom -> pattern_max_times ) ? 1: 0 ;
		
		case __match_digit_alpha_scale_none_limit_pattern_:
		case __match_digit_smart_alpha_scale_none_limit_pattern_:
		case __match_digit_strong_alpha_scale_none_limit_pattern_:
			return ( current_regular_expressions_atom -> pattern_times  <= times ) ? 1 : 0 ;

	}
	


}

void regular_expression_atom_logical_operation( int operation , int type , int _expression_scope ) {

	//	author: Jelo Wang
	//	since : 20090529
	//	(C)TOK	


	switch( operation ) {
		case _RegularExpressionsAtomOperationOr:
			regular_expressions_atom_walker -> operation = _RegularExpressionsAtomOperationOr ;
			//	dont needs seetting the priority cause the current version isnt surpports
			//	regular_expressions_atom_walker -> priority = _RegularExpressionsAtomOperationMiddle ;
			regular_expressions_atom_walker -> expression_scope = _expression_scope ;
		break ;
	}
			
/*	
	switch( type ) {

		case __match_smart_alpha_normal_limit_pattern_:					
		case __match_smart_alpha_scale_limit_pattern_:
		case __match_strong_alpha_normal_limit_pattern_:	
		case __match_strong_alpha_scale_limit_pattern_:
		case __match_Both_Smart_Strong_alpha_normal_limit_pattern_:
		case __match_Both_Smart_Strong_alpha_scale_limit_pattern_:
		case __match_digit_normal_limit_pattern_:	
		case __match_digit_scale_limit_pattern_:
		case __match_symbol_normal_limit_pattern_:						
		case __match_symbol_scale_limit_pattern_:	
		case __match_all_symbols_normal_limit_pattern_:			
		case __match_all_symbols_scale_limit_pattern_:
			switch( operation ) {
				case _RegularExpressionsAtomOperationOr:
					regular_expressions_atom_walker -> operation = _RegularExpressionsAtomOperationOr ;
					regular_expressions_atom_walker -> priority = _RegularExpressionsAtomOperationMiddle ;
					regular_expressions_atom_walker -> expression_scope = _expression_scope ;
				break ;
			}
		break ;

		case __match_smart_alpha_normal_none_limit_pattern_:								
		case __match_smart_alpha_scale_none_limit_pattern_:			
		case __match_strong_alpha_normal_none_limit_pattern_:		
		case __match_strong_alpha_scale_none_limit_pattern_:	
		case __match_Both_Smart_Strong_alpha_normal_none_limit_pattern_:
		case __match_Both_Smart_Strong_alpha_scale_none_limit_pattern_:
		case __match_digit_normal_none_limit_pattern_:				
		case __match_digit_scale_none_limit_pattern_:					
		case __match_symbol_normal_none_limit_pattern_:				
		case __match_symbol_scale_none_limit_pattern_:		
		case __match_all_symbols_normal_none_limit_pattern_:		
		case __match_all_symbols_scale_none_limit_pattern_:
			switch( operation ) {
				case _RegularExpressionsAtomOperationOr:
					regular_expressions_atom_walker -> operation = _RegularExpressionsAtomOperationOr ;
					regular_expressions_atom_walker -> priority = _RegularExpressionsAtomOperationLow ;
					regular_expressions_atom_walker -> expression_scope = _expression_scope ;
				break ;
			}
		break ;
//		case _normal_none_limit:
//		case _scale_none_limit:
//			regular_expressions_atom_walker -> global_operation = _RegularExpressionsAtomOperationOr ;
//			regular_expressions_atom_walker -> priority_operation = _RegularExpressionsAtomOperationLow ;
//		break ;
//		case _normal_limit:
//		case _scale_limit:
//			regular_expressions_atom_walker -> global_operation = _RegularExpressionsAtomOperationOr ;
//			regular_expressions_atom_walker -> priority_operation = _RegularExpressionsAtomOperationMiddle ;
//		break ;

	}
*/	

}

int regular_expression_atom_analyze () {

	//	author: Jelo Wang
	//	since : 20090528
	//	(C)TOK	

	int buffer_walker = 0 ;
	int have_recursive_expression = 0 ;
	int _expression_scope = 0 ;
	int walker = 0 ;
	char front_pattern = 0 ;
	char* buffer = (char* ) MALLOC ( sizeof(char) * regular_expressions . length + 1 ) ;

	if ( !buffer ) return 0 ;
	
	while ( !_string_overflowed(regular_expressions) ) {

		if ( '[' == _string_get(regular_expressions) ) {
			_string_walker_add(&regular_expressions,1) ;
			//	add nest
			ReecNestedFormNewAtom (&rex_nested_form) ;
		} 
		
		if ( '<' == _string_get(regular_expressions) ) {
			_string_walker_add(&regular_expressions,2) ;

			if (smart_alpha(_string_look(regular_expressions,0)) && '-' == _string_look(regular_expressions,1) && strong_alpha(_string_look(regular_expressions,3)) && digit(_string_look(regular_expressions,6)) ) {
				//<(a-zA-Z0-9)^1>、<(a-zA-Z0-9)^*>、<(a-zA-Z0-9){1,1}>、<(a-zA-Z0-9){1,*}>
				_string_walker_add(&regular_expressions,10) ;
				if ('^' == _string_look(regular_expressions,0)) {
					_string_walker_add(&regular_expressions,1) ;
					if ('*' == _string_look(regular_expressions,0)) {
						//<(a-zA-Z0-9)^*>
						_regular_expressions_atom_add_node( __match_digit_alpha_normal_none_limit_pattern_ , "NULL" , 0 , 0 ) ;
						//	add nested form atom handle
						ReecNestedFormAtomAddHandle (&rex_nested_form,regular_expressions_atom_walker) ;
					} else if (digit(_string_look(regular_expressions,0))) {
						//<(a-zA-Z0-9)^1>
						_regular_expressions_atom_add_node( __match_digit_alpha_normal_limit_pattern_ , "NULL" , _string_look(regular_expressions,0) - '0' , 0 ) ;
						//	add nested form atom handle
						ReecNestedFormAtomAddHandle (&rex_nested_form,regular_expressions_atom_walker) ;
					} 
				} else {
					_string_walker_add(&regular_expressions,1) ;
					if ('*' == _string_look(regular_expressions,2)) {
						//<(a-zA-Z0-9){1,*}>
						_regular_expressions_atom_add_node( __match_digit_alpha_scale_none_limit_pattern_ , "NULL" ,  _string_look(regular_expressions,0) - '0' , 0 ) ;
						//	add nested form atom handle
						ReecNestedFormAtomAddHandle (&rex_nested_form,regular_expressions_atom_walker) ;
					} else {
						//<(a-zA-Z0-9){1,1}>
						_regular_expressions_atom_add_node( __match_digit_alpha_scale_limit_pattern_ , "NULL" ,  _string_look(regular_expressions,0) - '0' , _string_look(regular_expressions,2) - '0' ) ;
						//	add nested form atom handle
						ReecNestedFormAtomAddHandle (&rex_nested_form,regular_expressions_atom_walker) ;
					}
				}
			} else if (smart_alpha(_string_look(regular_expressions,0)) && '-' == _string_look(regular_expressions,1) && digit(_string_look(regular_expressions,3))) {
				//<(a-z0-9)^1>、<(a-z0-9)^*>、<(a-z0-9){1,1}>、<a-z0-9){1,*}>
				_string_walker_add(&regular_expressions,7) ;
				if ('^' == _string_look(regular_expressions,0)) {
					_string_walker_add(&regular_expressions,1) ;
					if ('*' == _string_look(regular_expressions,0)) {
						//<(a-z0-9)^*>
						_regular_expressions_atom_add_node( __match_digit_smart_alpha_normal_none_limit_pattern_ , "NULL" , 0 , 0 ) ;
						//	add nested form atom handle
						ReecNestedFormAtomAddHandle (&rex_nested_form,regular_expressions_atom_walker) ;
					} else if (digit(_string_look(regular_expressions,0))) {
						//<(a-z0-9)^1>
						_regular_expressions_atom_add_node( __match_digit_smart_alpha_normal_limit_pattern_ , "NULL" , _string_look(regular_expressions,0) - '0' , 0 ) ;
						//	add nested form atom handle
						ReecNestedFormAtomAddHandle (&rex_nested_form,regular_expressions_atom_walker) ;
					} 
				} else {
					_string_walker_add(&regular_expressions,1) ;
					if ('*' == _string_look(regular_expressions,2)) {
						//<(a-z0-9){1,*}>
						_regular_expressions_atom_add_node( __match_digit_smart_alpha_scale_none_limit_pattern_ , "NULL" ,  _string_look(regular_expressions,0) - '0' , 0 ) ;
						//	add nested form atom handle
						ReecNestedFormAtomAddHandle (&rex_nested_form,regular_expressions_atom_walker) ;					
					} else {
						//<(a-z0-9){1,1}>
						_regular_expressions_atom_add_node( __match_digit_smart_alpha_scale_limit_pattern_ , "NULL" ,  _string_look(regular_expressions,0) - '0' , _string_look(regular_expressions,2) - '0' ) ;
						//	add nested form atom handle
						ReecNestedFormAtomAddHandle (&rex_nested_form,regular_expressions_atom_walker) ;
					}
				}
			} else if (strong_alpha(_string_look(regular_expressions,0)) && '-' == _string_look(regular_expressions,1) && digit(_string_look(regular_expressions,3))) {
				//<(A-Z0-9)^1>、<(A-Z0-9)^*>、<(A-Z0-9){1,1}>、<A-Z0-9){1,*}>
				_string_walker_add(&regular_expressions,7) ;
				if ('^' == _string_look(regular_expressions,0)) {
					_string_walker_add(&regular_expressions,1) ;
					if ('*' == _string_look(regular_expressions,0)) {
						//<(A-Z0-9)^*>
						_regular_expressions_atom_add_node( __match_digit_strong_alpha_normal_none_limit_pattern_ , "NULL" , 0 , 0 ) ;
						//	add nested form atom handle
						ReecNestedFormAtomAddHandle (&rex_nested_form,regular_expressions_atom_walker) ;				
					} else if (digit(_string_look(regular_expressions,0))) {
						//<(A-Z0-9)^1>
						_regular_expressions_atom_add_node( __match_digit_strong_alpha_normal_limit_pattern_ , "NULL" , _string_look(regular_expressions,0) - '0' , 0 ) ;
						//	add nested form atom handle
						ReecNestedFormAtomAddHandle (&rex_nested_form,regular_expressions_atom_walker) ;
					} 
				} else {
					_string_walker_add(&regular_expressions,1) ;
					if ('*' == _string_look(regular_expressions,2)) {
						//<(A-Z0-9){1,*}>
						_regular_expressions_atom_add_node( __match_digit_strong_alpha_scale_none_limit_pattern_ , "NULL" ,  _string_look(regular_expressions,0) - '0' , 0 ) ;
						//	add nested form atom handle
						ReecNestedFormAtomAddHandle (&rex_nested_form,regular_expressions_atom_walker) ;
					} else {
						//<(A-Z0-9){1,1}>
						_regular_expressions_atom_add_node( __match_digit_strong_alpha_scale_limit_pattern_ , "NULL" ,  _string_look(regular_expressions,0) - '0' , _string_look(regular_expressions,2) - '0' ) ;
						//	add nested form atom handle
						ReecNestedFormAtomAddHandle (&rex_nested_form,regular_expressions_atom_walker) ;
					}
				}
			} else if (smart_alpha(_string_look(regular_expressions,0)) && '-' == _string_look(regular_expressions,1) && strong_alpha(_string_look(regular_expressions,3)) ) {
				//<(a-zA-Z)^1>、<(a-zA-Z)^*>、<(a-zA-Z){1,1}>、<(a-zA-Z){1,*}>
				_string_walker_add(&regular_expressions,7) ;				
				if ('^' == _string_look(regular_expressions,0)) {
					_string_walker_add(&regular_expressions,1) ;
					if ('*' == _string_look(regular_expressions,0)) {
						//<(a-zA-Z)^*>
						_regular_expressions_atom_add_node( __match_Both_Smart_Strong_alpha_normal_none_limit_pattern_ , "NULL" , 0 , 0 ) ;
						//	add nested form atom handle
						ReecNestedFormAtomAddHandle (&rex_nested_form,regular_expressions_atom_walker) ;
					} else if (digit(_string_look(regular_expressions,0))) {
						//<(a-zA-Z)^1>
						_regular_expressions_atom_add_node( __match_Both_Smart_Strong_alpha_normal_limit_pattern_ , "NULL" , _string_look(regular_expressions,0) - '0' , 0 ) ;
						//	add nested form atom handle
						ReecNestedFormAtomAddHandle (&rex_nested_form,regular_expressions_atom_walker) ;
					} 
				} else {
					_string_walker_add(&regular_expressions,1) ;
					if ('*' == _string_look(regular_expressions,2)) {
						//<(a-zA-Z){1,*}>
						_regular_expressions_atom_add_node( __match_Both_Smart_Strong_alpha_scale_none_limit_pattern_ , "NULL" ,  _string_look(regular_expressions,0) - '0' , 0 ) ;
						//	add nested form atom handle
						ReecNestedFormAtomAddHandle (&rex_nested_form,regular_expressions_atom_walker) ;
					} else {
						//<(a-zA-Z){1,1}>
						_regular_expressions_atom_add_node( __match_Both_Smart_Strong_alpha_scale_limit_pattern_ , "NULL" ,  _string_look(regular_expressions,0) - '0' , _string_look(regular_expressions,2) - '0' ) ;
						//	add nested form atom handle
						ReecNestedFormAtomAddHandle (&rex_nested_form,regular_expressions_atom_walker) ;
					}
				}
			
			} else if (smart_alpha(_string_look(regular_expressions,0)) && '-' == _string_look(regular_expressions,1) && ')' == _string_look(regular_expressions,3)) {
				//<(a-z)^1>、<(a-z)^*>、<(a-z){1,1}>、<(a-z){1,*}>
				_string_walker_add(&regular_expressions,4) ;

				if ('^' == _string_look(regular_expressions,0)) {
					_string_walker_add(&regular_expressions,1) ;
					if ('*' == _string_look(regular_expressions,0)) {
						//<(a-z)^*>
						_regular_expressions_atom_add_node( __match_smart_alpha_normal_none_limit_pattern_ , "NULL" , 0 , 0 ) ;
						//	add nested form atom handle
						ReecNestedFormAtomAddHandle (&rex_nested_form,regular_expressions_atom_walker) ;
					} else if (digit(_string_look(regular_expressions,0))) {
						//<(a-z)^1>
						_regular_expressions_atom_add_node( __match_smart_alpha_normal_limit_pattern_ , "NULL" , _string_look(regular_expressions,0) - '0' , 0 ) ;
						//	add nested form atom handle
						ReecNestedFormAtomAddHandle (&rex_nested_form,regular_expressions_atom_walker) ;
					} 
				} else if ('{' == _string_look(regular_expressions,0)) {
					_string_walker_add(&regular_expressions,1) ;
					if ('*' == _string_look(regular_expressions,2)) {
						//<(a-z){1,*}>
						_regular_expressions_atom_add_node( __match_smart_alpha_scale_none_limit_pattern_ , "NULL" , _string_look(regular_expressions,0) - '0' , 0 ) ;
						//	add nested form atom handle
						ReecNestedFormAtomAddHandle (&rex_nested_form,regular_expressions_atom_walker) ;					
					} else {
						//<(a-z){1,1}>
						_regular_expressions_atom_add_node( __match_smart_alpha_scale_limit_pattern_ , "NULL" , _string_look(regular_expressions,0) - '0' , _string_look(regular_expressions,2) - '0' ) ;
						//	add nested form atom handle
						ReecNestedFormAtomAddHandle (&rex_nested_form,regular_expressions_atom_walker) ;					
					}
				}

				

			} else if (strong_alpha(_string_look(regular_expressions,0)) && '-' == _string_look(regular_expressions,1) && ')' == _string_look(regular_expressions,3)) {
				//<(A-Z)^1>、<(A-Z)^*>、<(A-Z){1,1}>、<(A-Z){1,*}>
				_string_walker_add(&regular_expressions,4) ;

				if ('^' == _string_look(regular_expressions,0)) {
					_string_walker_add(&regular_expressions,1) ;
					if ('*' == _string_look(regular_expressions,0)) {
						//<(A-Z)^*>
						_regular_expressions_atom_add_node( __match_strong_alpha_normal_none_limit_pattern_ , "NULL" , 0 , 0 ) ;
						//	add nested form atom handle
						ReecNestedFormAtomAddHandle (&rex_nested_form,regular_expressions_atom_walker) ;					
					} else if (digit(_string_look(regular_expressions,0))) {
						//<(A-Z)^1>
						_regular_expressions_atom_add_node( __match_strong_alpha_normal_limit_pattern_ , "NULL" , _string_look(regular_expressions,0) - '0' , 0 ) ;
						//	add nested form atom handle
						ReecNestedFormAtomAddHandle (&rex_nested_form,regular_expressions_atom_walker) ;				
					} 
				} else if ('{' == _string_look(regular_expressions,0)) {
					_string_walker_add(&regular_expressions,1) ;
					if ('*' == _string_look(regular_expressions,2)) {
						//<(A-Z){1,*}>
						_regular_expressions_atom_add_node( __match_strong_alpha_scale_none_limit_pattern_ , "NULL" , _string_look(regular_expressions,0) - '0' , 0 ) ;
						//	add nested form atom handle
						ReecNestedFormAtomAddHandle (&rex_nested_form,regular_expressions_atom_walker) ;					
					} else {
						//<(A-Z){1,1}>
						_regular_expressions_atom_add_node( __match_strong_alpha_scale_limit_pattern_ , "NULL" , _string_look(regular_expressions,0) - '0' , _string_look(regular_expressions,2) - '0' ) ;
						//	add nested form atom handle
						ReecNestedFormAtomAddHandle (&rex_nested_form,regular_expressions_atom_walker) ;					
					}
				}
				
				

			} else if (digit(_string_look(regular_expressions,0)) && '-' == _string_look(regular_expressions,1)) {
				//<(0-9)^1>、<(0-9)^*>、<(0-9){1,1}>、<(0-9){1,*}>
				_string_walker_add(&regular_expressions,4) ;
				if ('^' == _string_look(regular_expressions,0)) {
					_string_walker_add(&regular_expressions,1) ;
					if ('*'==_string_look(regular_expressions,0)) {
						_regular_expressions_atom_add_node( __match_digit_normal_none_limit_pattern_ , "NULL" , 0, 0 ) ;
						//	add nested form atom handle
						ReecNestedFormAtomAddHandle (&rex_nested_form,regular_expressions_atom_walker) ;					
					} else {
						_regular_expressions_atom_add_node( __match_digit_normal_limit_pattern_ , "NULL" , _string_look(regular_expressions,0) - '0' , 0) ;
						//	add nested form atom handle
						ReecNestedFormAtomAddHandle (&rex_nested_form,regular_expressions_atom_walker) ;
					}
				} else {
					_string_walker_add(&regular_expressions,1) ;
					if ('*'==_string_look(regular_expressions,2)) {
						_regular_expressions_atom_add_node( __match_digit_scale_none_limit_pattern_ , "NULL"  , _string_look(regular_expressions,0) - '0' , 0 ) ;
						//	add nested form atom handle
						ReecNestedFormAtomAddHandle (&rex_nested_form,regular_expressions_atom_walker) ;				
					} else {
						_regular_expressions_atom_add_node( __match_digit_scale_limit_pattern_ , "NULL"  , _string_look(regular_expressions,0) - '0' , _string_look(regular_expressions,2) - '0' ) ;
						//	add nested form atom handle
						ReecNestedFormAtomAddHandle (&rex_nested_form,regular_expressions_atom_walker) ;				
					}
				}

				

			} else if ( '*' == _string_look(regular_expressions,0) ) {
				//<(*)^1>、<(*)^*>、<(*){1,1}>、<(*){1,*}>
				_string_walker_add(&regular_expressions,2) ;

				if ('^' == _string_look(regular_expressions,0)) {
					_string_walker_add(&regular_expressions,1) ;
					if ('*'==_string_look(regular_expressions,0)) {
						_regular_expressions_atom_add_node( __match_all_symbols_normal_none_limit_pattern_ , "NULL" , 0 , 0 ) ;
						//	add nested form atom handle
						ReecNestedFormAtomAddHandle (&rex_nested_form,regular_expressions_atom_walker) ;					
					} else {
						_regular_expressions_atom_add_node( __match_all_symbols_normal_limit_pattern_ , "NULL" , _string_look(regular_expressions,0) - '0' , 0) ;
						//	add nested form atom handle
						ReecNestedFormAtomAddHandle (&rex_nested_form,regular_expressions_atom_walker) ;					
					}
				} else {
					_string_walker_add(&regular_expressions,1) ;
					if ('*'==_string_look(regular_expressions,2)) {
						_regular_expressions_atom_add_node( __match_all_symbols_scale_none_limit_pattern_ , "NULL" , _string_look(regular_expressions,0) - '0' , 0 ) ;
						//	add nested form atom handle
						ReecNestedFormAtomAddHandle (&rex_nested_form,regular_expressions_atom_walker) ;					
					} else {
						_regular_expressions_atom_add_node( __match_all_symbols_scale_limit_pattern_ , "NULL" , _string_look(regular_expressions,0) - '0' , _string_look(regular_expressions,2) - '0' ) ;
						//	add nested form atom handle
						ReecNestedFormAtomAddHandle (&rex_nested_form,regular_expressions_atom_walker) ;					
					}
				}

				

			} else {
				//<(symbol)^1>、<(symbol)^*>、<(symbol){1,1}>、<(symbol){1,*}>
				buffer_walker = 0 ;
				while (1) {

					if ( ')' == _string_look(regular_expressions,0) )
						break ;
					buffer[ buffer_walker ] = _string_look(regular_expressions,0) ;
					_string_next(&regular_expressions) ;
					buffer_walker ++ ;

				}

				_string_next(&regular_expressions) ;
				buffer[ buffer_walker ] = '\0' ;
				
				if ('^' == _string_look(regular_expressions,0)) {
					_string_walker_add(&regular_expressions,1) ;
					if ('*'==_string_look(regular_expressions,0)) {
						_regular_expressions_atom_add_node( __match_symbol_normal_none_limit_pattern_, buffer , 0 , 0 ) ;
						//	add nested form atom handle
						ReecNestedFormAtomAddHandle (&rex_nested_form,regular_expressions_atom_walker) ;					
					} else {
						_regular_expressions_atom_add_node( __match_symbol_normal_limit_pattern_ , buffer , _string_look(regular_expressions,0) - '0' , 0) ;
						//	add nested form atom handle
						ReecNestedFormAtomAddHandle (&rex_nested_form,regular_expressions_atom_walker) ;
					}
				} else {
					_string_walker_add(&regular_expressions,1) ;
					if ('*'==_string_look(regular_expressions,2)) {
						_regular_expressions_atom_add_node( __match_symbol_scale_none_limit_pattern_ , buffer , _string_look(regular_expressions,0) - '0' , 0 ) ;
						//	add nested form atom handle
						ReecNestedFormAtomAddHandle (&rex_nested_form,regular_expressions_atom_walker) ;
					} else {
						_regular_expressions_atom_add_node( __match_symbol_scale_limit_pattern_ , buffer , _string_look(regular_expressions,0) - '0' , _string_look(regular_expressions,2) - '0' ) ;
						//	add nested form atom handle
						ReecNestedFormAtomAddHandle (&rex_nested_form,regular_expressions_atom_walker) ;		
					}
				}

			}
			
			_string_reset_walker_with_element(&regular_expressions,'>') ;

			if ( ']' == _string_look(regular_expressions,1) ) {
				_string_walker_add(&regular_expressions,2) ;							
			}

			if ('|' == _string_look(regular_expressions,1))
				regular_expression_atom_logical_operation(_RegularExpressionsAtomOperationOr , regular_expressions_atom_walker -> pattern_type , ++ _expression_scope ) ;
			else if ( '|' == front_pattern )
				regular_expression_atom_logical_operation(_RegularExpressionsAtomOperationOr , regular_expressions_atom_walker -> pattern_type , 0 ) ;
		
			front_pattern = _string_look(regular_expressions,1) ;

			if ( '[' == _string_get(regular_expressions) ) {
				_string_walker_add(&regular_expressions,1) ;
				//	add nest
				ReecNestedFormNewAtom (&rex_nested_form) ;
			} 
		
			_string_reset_walker_with_element(&regular_expressions,'<') ;
				
		} else _string_next(&regular_expressions) ;

	}

	FREE(buffer) ;

	return 1 ;

/*
	//set recursive times of regular_expressions_atom in a same recursive scope
	//scope = <(<(a-z)^*>|<(*)^1>){1,1}>
	//recursive times = {1,1}

	//set operation scope of regular_expressions_atom in a same operation scope
	//scope = <(<(a-z)^*>|<(*)^1>){1,1}>|<(gtkings)^1>|<(china)^1>

	have_recursive_expression = 0 ;
	LastRexAtom = regular_expressions_atom_walker ;
	regular_expressions_atom_walker = regular_expressions_atom_walker -> front ;

	while (regular_expressions_atom_walker) {
		
		if (LastRexAtom -> recursive_expression && regular_expressions_atom_walker -> recursive_expression == LastRexAtom -> recursive_expression) {
			regular_expressions_atom_walker -> recursive_type = LastRexAtom -> recursive_type ;
			regular_expressions_atom_walker -> recursive_times = LastRexAtom -> recursive_times ;
			regular_expressions_atom_walker -> recursive_max_times = LastRexAtom -> recursive_max_times ;
//			regular_expressions_atom_walker -> global_operation = LastRexAtom -> global_operation ;
		} 
		
		LastRexAtom = regular_expressions_atom_walker ;	
		regular_expressions_atom_walker = regular_expressions_atom_walker -> front ;
	}
*/

}
	
int regular_expression_atom_matching( int type , RegularExpressionsAtom* regularexpressionsatom) {
	
	//	author: Jelo Wang
	//	since : 20090528
	//	(C)TOK	

	int patter_type = 0 ;

	if ( -1 == type ) {
		patter_type = regular_expressions_atom_walker -> pattern_type ;
		current_regular_expressions_atom = regular_expressions_atom_walker ;
	} else {
		patter_type = type ;
		current_regular_expressions_atom = regularexpressionsatom ;
	}

	switch( patter_type ) {
			
		//<(a-z)^1>   
		case __match_smart_alpha_normal_limit_pattern_:
			if (!match_alpha_normal_limit_pattern( _smart_ ))
				return 0 ;
		break ;
		//<(a-z)^*>    
		case __match_smart_alpha_normal_none_limit_pattern_:
			if (!match_alpha_none_limit_pattern( _smart_ ))
				return 0 ;
		break ;
		//<(a-z){1,1}> 
		case __match_smart_alpha_scale_limit_pattern_:
			if (!match_alpha_scale_limit_pattern( _smart_ ))
				return 0 ;
		break ;
		//<(a-z){1,*}> 
		case __match_smart_alpha_scale_none_limit_pattern_:
			if (!match_alpha_scale_none_limit_pattern( _smart_ ))
				return 0 ;
		break ;
		//<(A-Z)^1>   
		case __match_strong_alpha_normal_limit_pattern_:
			if (!match_alpha_normal_limit_pattern( _strong_ ))
				return 0 ;
		break ;
		//<(A-Z)^*>    
		case __match_strong_alpha_normal_none_limit_pattern_:
			if (!match_alpha_none_limit_pattern( _strong_ ))
				return 0 ;
		break ;
		//<(A-Z){1,1}> 
		case __match_strong_alpha_scale_limit_pattern_:
			if (!match_alpha_scale_limit_pattern( _strong_ ))
				return 0 ;
		break ;
		//<(A-Z){1,*}> 
		case __match_strong_alpha_scale_none_limit_pattern_:
			if (!match_alpha_scale_none_limit_pattern( _strong_ ))
				return 0 ;
		break ;
		//<(a-zA-Z)^1>   
		case __match_Both_Smart_Strong_alpha_normal_limit_pattern_:
			if (!match_alpha_normal_limit_pattern( _smart_ | _strong_ ))
				return 0 ;
		break ;
		//<(a-zA-Z)^*>    
		case __match_Both_Smart_Strong_alpha_normal_none_limit_pattern_:
			if (!match_alpha_none_limit_pattern( _smart_ | _strong_ ))
				return 0 ;
		break ;
		//<(a-zA-Z){1,1}> 
		case __match_Both_Smart_Strong_alpha_scale_limit_pattern_:
			if (!match_alpha_scale_limit_pattern( _smart_ | _strong_ ))
				return 0 ;
		break ;
		//<(a-zA-Z){1,*}> 
		case __match_Both_Smart_Strong_alpha_scale_none_limit_pattern_:
			if (!match_alpha_scale_none_limit_pattern( _smart_ | _strong_ ))
				return 0 ;
		break ;
		//<(0-9)^1>
		case __match_digit_normal_limit_pattern_:
			if (!match_digit_pattern(__match_digit_normal_limit_pattern_))
				return 0 ;
		break ;
		//<(0-9)^*>
		case __match_digit_normal_none_limit_pattern_:
			if (!match_digit_pattern(__match_digit_normal_none_limit_pattern_))
				return 0 ;
		break ;
		//<(0-9){1,1}>
		case __match_digit_scale_limit_pattern_:
			if (!match_digit_pattern(__match_digit_scale_limit_pattern_))
				return 0 ;
		break ;
		//<(0-9){1,*}>
		case __match_digit_scale_none_limit_pattern_:
			if (!match_digit_pattern(__match_digit_scale_none_limit_pattern_))
				return 0 ;
		break ;
		//<(symbol)^1>
		case __match_symbol_normal_limit_pattern_:
			if (!match_symbol_pattern(__match_symbol_normal_limit_pattern_))
				return 0 ;				
		break ;
		//<(symbol)^*>
		case __match_symbol_normal_none_limit_pattern_:
			if (!match_symbol_pattern(__match_symbol_normal_none_limit_pattern_))
				return 0 ;
		break ;
		//<(symbol){1,1}>
		case __match_symbol_scale_limit_pattern_:
			if (!match_symbol_pattern(__match_symbol_scale_limit_pattern_))
				return 0 ;
		break ;
		//<(symbol){1,*}>
		case __match_symbol_scale_none_limit_pattern_:
			if (!match_symbol_pattern(__match_symbol_scale_none_limit_pattern_))
				return 0 ;
		break ;
		//<(*)^1>
		case __match_all_symbols_normal_limit_pattern_:
			if (!match_all_symbol_pattern(__match_all_symbols_normal_limit_pattern_))
				return 0 ;
		break ;
		//<(*)^*>
		case __match_all_symbols_normal_none_limit_pattern_:
			if (!match_all_symbol_pattern(__match_all_symbols_normal_none_limit_pattern_))
				return 0 ;
		break ;
		//<(*){1,1}>
		case __match_all_symbols_scale_limit_pattern_:
			if (!match_all_symbol_pattern(__match_all_symbols_scale_limit_pattern_))
				return 0 ;
		break ;
		//<(*){1,*}>
		case __match_all_symbols_scale_none_limit_pattern_:
			if (!match_all_symbol_pattern(__match_all_symbols_scale_none_limit_pattern_))
				return 0 ;
		break ;
		//<(a-zA-Z0-9)^1>
		case __match_digit_alpha_normal_limit_pattern_:							
			if (!match_digit_alpha_pattern(__match_digit_alpha_normal_limit_pattern_))
				return 0 ;
		break ;
		//<(a-zA-Z0-9)^*>
		case __match_digit_alpha_normal_none_limit_pattern_:					
			if (!match_digit_alpha_pattern(__match_digit_alpha_normal_none_limit_pattern_))
				return 0 ;
		break ;
		//<(a-zA-Z0-9){1,1}>
		case __match_digit_alpha_scale_limit_pattern_:							
			if (!match_digit_alpha_pattern(__match_digit_alpha_scale_limit_pattern_))
				return 0 ;
		break ;
		//<(a-zA-Z0-9){1,*}>
		case __match_digit_alpha_scale_none_limit_pattern_:						
			if (!match_digit_alpha_pattern(__match_digit_alpha_scale_none_limit_pattern_))
				return 0 ;
		break ;
		//<(a-z0-9)^1>
		case __match_digit_smart_alpha_normal_limit_pattern_:				
			if (!match_digit_alpha_pattern(__match_digit_smart_alpha_normal_limit_pattern_))
				return 0 ;
		break ;
		//<(a-z0-9)^*>
		case __match_digit_smart_alpha_normal_none_limit_pattern_:				
			if (!match_digit_alpha_pattern(__match_digit_smart_alpha_normal_none_limit_pattern_))
				return 0 ;
		break ;
		//<(a-z0-9){1,1}>
		case __match_digit_smart_alpha_scale_limit_pattern_:					
			if (!match_digit_alpha_pattern(__match_digit_smart_alpha_scale_limit_pattern_))
				return 0 ;
		break ;
		//<(a-z0-9){1,*}>
		case __match_digit_smart_alpha_scale_none_limit_pattern_:				
			if (!match_digit_alpha_pattern(__match_digit_smart_alpha_scale_none_limit_pattern_))
				return 0 ;
		break ;
		//<(A-Z0-9)^1>
		case __match_digit_strong_alpha_normal_limit_pattern_:					
			if (!match_digit_alpha_pattern(__match_digit_strong_alpha_normal_limit_pattern_))
				return 0 ;
		break ;
		//<(A-Z0-9)^*>
		case __match_digit_strong_alpha_normal_none_limit_pattern_:				
			if (!match_digit_alpha_pattern(__match_digit_strong_alpha_normal_none_limit_pattern_))
				return 0 ;
		break ;
		//<(A-Z0-9){1,1}>
		case __match_digit_strong_alpha_scale_limit_pattern_:					
			if (!match_digit_alpha_pattern(__match_digit_strong_alpha_scale_limit_pattern_))
				return 0 ;
		break ;
		//<(A-Z0-9){1,*}>
		case __match_digit_strong_alpha_scale_none_limit_pattern_:				
			if (!match_digit_alpha_pattern(__match_digit_strong_alpha_scale_none_limit_pattern_))
				return 0 ;
		break ;

		default:

			return 0 ;

	}

	return 1 ;

}


int regular_expression_atom_matching_begin () {
	
	//	author: Jelo Wang
	//	since : 20100330
	//	(C)TOK
	
	int loop_controller = 0 ;
	int walker_saver = 0 ;
	int walker_saver_ii = 0 ;
	int totall_times = 0 ;
	int _recursive_times = 0 ;
	int times = 0 ;
	
	walker_saver_ii = object_string.walker ;

restart:		

	for (_regular_expressions_atom_walker_initialize () ;!_string_overflowed( object_string ) && regular_expressions_atom_walker ;) {


		if (_RegularExpressionsAtomOperationOr == regular_expressions_atom_walker->operation) {
			
			loop_controller = 1 ;
			while (regular_expressions_atom_walker && regular_expressions_atom_walker->operation && loop_controller) {
				walker_saver = pattern_elements_matched.walker ;
				//	as for save walker , because _RegularExpressionsAtomOperationOr the engine should check all operation-chain
				walker_saver_ii = object_string.walker ;
				if (!regular_expression_atom_matching( -1 , regular_expressions_atom_walker)) {
					if ( 0 == regular_expressions_atom_walker->expression_scope ) {
						__restart_engine_ () ;
						goto restart ;
					}
					regular_expressions_atom_walker = regular_expressions_atom_walker -> next ;
					pattern_elements_matched.walker = walker_saver ;
					walker_saver_ii ++ ;
					object_string.walker = walker_saver_ii ;
					continue ;
				} else {
					regular_pattern_matched = 1 ;
					loop_controller = 0 ;
					regular_expressions_atom_walker->pattern_matched_times -= current_regular_expressions_atom->pattern_matched_times ;
				}
			}
			
			if (1 == loop_controller){
				if ( RS_LEVEL_1 == reecmonitor.rs_level ) {
					__restart_engine_() ;
				}				
 				__reset_engine_ () ;
				_string_next(&object_string) ;
				continue ;
			} else {
				//<...>|<...>|<...> let engine skip other atoms as long as one atom was matched
				while (regular_expressions_atom_walker && regular_expressions_atom_walker->expression_scope)
					regular_expressions_atom_walker = regular_expressions_atom_walker->next ;
				regular_pattern_matched = 1 ;
			}

		} else if ( 0 == regular_expressions_atom_walker->operation ) {
			if (!regular_expression_atom_matching( -1 , regular_expressions_atom_walker)) {
				if ( RS_LEVEL_1 == reecmonitor.rs_level ) {
					__restart_engine_() ;
				}
				walker_saver_ii ++ ;
				object_string.walker = walker_saver_ii ;
				__reset_engine_ () ;
				continue ;
			} else {				
				regular_pattern_matched = 1 ;
				regular_expressions_atom_walker->pattern_matched_times -= current_regular_expressions_atom->pattern_matched_times ;	
			}

		} 



/*
		walker_saver_ii = object_string.walker ;
		if (!regular_expression_atom_matching( -1 , regular_expressions_atom_walker)) {
			if ( RS_LEVEL_1 == reecmonitor.rs_level || _string_overflowed(object_string)) {
				return 0 ;
			}
			object_string.walker = walker_saver_ii ;
			__reset_engine_ () ;
			_string_next(&object_string) ;
			continue ;
		} else {				
			regular_pattern_matched = 1 ;
			regular_expressions_atom_walker->pattern_matched_times -= current_regular_expressions_atom->pattern_matched_times ; 
		}
*/
		(regular_expressions_atom_walker) ? (regular_expressions_atom_walker = regular_expressions_atom_walker->next) : 0 ;


	}

	return (regular_expressions_atom_walker || !regular_pattern_matched) ? 0 : 1 ;

}




int regular_expression_atom_nested_matching () {
	
	//	author: Jelo Wang
	//	since : 20100330
	//	(C)TOK
	
	int loop_controller = 0 ;
	int walker_saver = 0 ;
	int walker_saver_ii = 0 ;
	int totall_times = 0 ;
	int _recursive_times = 0 ;
	int times = 0 ;
	
	REXNESTED_FROM* nested_walker = 0 ;

	for ( nested_walker = rex_nested_form.nested_head ; nested_walker ; nested_walker = nested_walker->nested_next ) {

		walker_saver_ii = object_string.walker ;
		
restart:
		for ( regular_expressions_atom_walker = nested_walker->atom->rea_head ;!_string_overflowed( object_string ) && regular_expressions_atom_walker ;) {

			if (_RegularExpressionsAtomOperationOr == regular_expressions_atom_walker->operation) {

				loop_controller = 1 ;
				while (regular_expressions_atom_walker && regular_expressions_atom_walker->operation && loop_controller) {
					walker_saver = pattern_elements_matched.walker ;
					//	as for save walker , because _RegularExpressionsAtomOperationOr the engine should check all operation-chain
					walker_saver_ii = object_string.walker ;					
					if (!regular_expression_atom_matching( -1 , regular_expressions_atom_walker)) {
						if ( 0 == regular_expressions_atom_walker->expression_scope ) {
							__restart_engine_ () ;
							goto restart ;
						}
						regular_expressions_atom_walker = regular_expressions_atom_walker -> next ;
						pattern_elements_matched.walker = walker_saver ;
						walker_saver_ii ++ ;
						object_string.walker = walker_saver_ii ;
						continue ;
					} else {
						regular_pattern_matched = 1 ;
						loop_controller = 0 ;
						regular_expressions_atom_walker->pattern_matched_times -= current_regular_expressions_atom->pattern_matched_times ;
					}
				}

				if (1 == loop_controller){
					if ( RS_LEVEL_1 == reecmonitor.rs_level ) {
						regular_pattern_matched = 0 ;
						pattern_elements_matched.walker = 0;
						regular_expressions_atom_walker = nested_walker->atom->rea_head ;
					}				
					__reset_engine_ () ;
					_string_next(&object_string) ;
					continue ;
				} else {
					//<...>|<...>|<...> let engine skip other atoms as long as one atom was matched
					while (regular_expressions_atom_walker && regular_expressions_atom_walker->expression_scope)
						regular_expressions_atom_walker = regular_expressions_atom_walker->next ;
					regular_pattern_matched = 1 ;
				}

			} else if ( 0 == regular_expressions_atom_walker->operation ) {
				if (!regular_expression_atom_matching( -1 , regular_expressions_atom_walker)) {
					if ( RS_LEVEL_1 == reecmonitor.rs_level ) {
						// restart engine
						regular_pattern_matched = 0 ;
						pattern_elements_matched.walker = 0;
						regular_expressions_atom_walker = nested_walker->atom->rea_head ;
					}
					walker_saver_ii ++ ;
					object_string.walker = walker_saver_ii ;
					__reset_engine_ () ;
					continue ;
				} else {				
					regular_pattern_matched = 1 ;
					regular_expressions_atom_walker->pattern_matched_times -= current_regular_expressions_atom->pattern_matched_times ;	
				}

			} 

			(regular_expressions_atom_walker) ? (regular_expressions_atom_walker = regular_expressions_atom_walker->next) : 0 ;


		}
		
		_string_add( &pattern_elements_matched , '\0' ) ;
	
		//	Jelo Wang Edited 2012.12.28
		if ( 0 < strlen ( pattern_elements_matched.data ) ) {
			
			FREE(object_string.data) ;
			object_string.data = (char* ) MALLOC ( pattern_elements_matched.walker + 1 ) ;
			if ( 0 == object_string.data ) return 0 ;
			strcpy(object_string.data,pattern_elements_matched.data) ;
			object_string.walker = 0 ;
			object_string.length = pattern_elements_matched.walker ;
			
		} else {
			object_string.walker = 0 ;
		}
		//	Jelo Wang Editting Finished
		
		if ( nested_walker->nested_next ) {
			pattern_elements_matched.walker = 0 ;
			regular_pattern_matched = 0 ;
		}

	}

	return (nested_walker || !regular_pattern_matched) ? 0 : 1 ;

}

int TOKRegularExpressionEngineBooleanRun( char* regular_expression , char* string , int level ) {
	
	//	author: Jelo Wang
	//	since : 20090528
	//	(C)TOK	

	//模式串與輸入串比較，如果匹配成功，返回布爾值真

# ifdef REEC_BENCHMARK
	int parserstime = 0 ;
	int parseretime = 0 ;
	int rexstime = 0 ;
	int rexetime = 0 ;	
# endif
	
	if ( !regular_expression || !string )
		return 0 ;
	
	reecmonitor.rs_level = level ;

	_string_destroy( &pattern_elements_matched ) ;
	_regular_expressions_atom_table_initialize () ;
	
	_string_initialize( &regular_expressions , regular_expression ) ;
	_string_initialize( &object_string , string ) ;
	_string_initialize_with_length( &pattern_elements_matched , strlen(string) + 1 ) ;


# ifdef REEC_BENCHMARK
	parserstime = clock () ;
# endif

	if ( 0 == regular_expression_atom_analyze () ) {
		_regular_expressions_atom_table_destroy () ;
		_string_destroy( &regular_expressions ) ;
		_string_destroy( &object_string ) ;
		_string_destroy( &pattern_elements_matched ) ;
		ReecNestedFormAtomDestroy (&rex_nested_form) ;
		return 0 ;
	}
	
# ifdef REEC_BENCHMARK
	parseretime = clock () ;
	printf ( "Rex Parsing Cost : %d\n" , parseretime-parserstime ) ;
# endif

# ifdef REEC_BENCHMARK
	rexstime = clock () ;
# endif

	if ( 0 < rex_nested_form.totall_nest ) {
		if (!regular_expression_atom_nested_matching()) {
			_regular_expressions_atom_table_destroy () ;
			_string_destroy( &regular_expressions ) ;
			_string_destroy( &object_string ) ;
			_string_destroy( &pattern_elements_matched ) ;
			ReecNestedFormAtomDestroy (&rex_nested_form) ;
			return 0 ;
		}
		
	} else {
		if (!regular_expression_atom_matching_begin()) {
			_regular_expressions_atom_table_destroy () ;
			_string_destroy( &regular_expressions ) ;
			_string_destroy( &object_string ) ;
			_string_destroy( &pattern_elements_matched ) ;
			ReecNestedFormAtomDestroy (&rex_nested_form) ;
			return 0 ;
		}
	}
	
	_regular_expressions_atom_table_destroy () ;
	_string_destroy( &regular_expressions ) ;
	ReecNestedFormAtomDestroy (&rex_nested_form) ;

//	Jelo Wang Edited 2012.12.28
#if 0
	if (pattern_elements_matched.walker != object_string.length ) {
		_string_destroy( &object_string ) ;
		_string_destroy( &pattern_elements_matched ) ;
		return 0 ;
	}
#endif
//	End

	_string_destroy( &object_string ) ;
	_string_destroy( &pattern_elements_matched ) ;

# ifdef REEC_BENCHMARK
	rexetime = clock () ;
	printf ( "Rex Decoding Cost : %d\n" , rexetime-rexstime ) ;
# endif

	return 1 ;

}

char* TOKRegularExpressionEngineRun( char* regular_expression , char* string , int level ) {
	
	//	author: Jelo Wang
	//	since : 20090528
	//	(C)TOK	

# ifdef REEC_BENCHMARK
	int parserstime = 0 ;
	int parseretime = 0 ;
	int rexstime = 0 ;
	int rexetime = 0 ;	
# endif

	if ( !regular_expression || !string )
		return 0 ;
	
	reecmonitor.rs_level = level ;
	
	ReecNestedFormAtomDestroy (&rex_nested_form) ;
	_string_destroy( &pattern_elements_matched ) ;
	_regular_expressions_atom_table_initialize () ;

	_string_initialize( &regular_expressions , regular_expression ) ;
	_string_initialize( &object_string , string ) ;
	_string_initialize_with_length( &pattern_elements_matched , strlen(string) + 1 ) ;

# ifdef REEC_BENCHMARK
	parserstime = clock () ;
# endif

	if ( 0 == regular_expression_atom_analyze () ) {
		_string_destroy( &regular_expressions ) ;
		_string_destroy( &object_string ) ;
		_string_destroy( &pattern_elements_matched ) ;
		_regular_expressions_atom_table_destroy () ;
		ReecNestedFormAtomDestroy (&rex_nested_form) ;
		return 0 ;
	}		

# ifdef REEC_BENCHMARK
	parseretime = clock () ;
	printf ( "Rex Parsing Cost : %d\n" , parseretime-parserstime ) ;
# endif

# ifdef REEC_BENCHMARK
	rexstime = clock () ;
# endif

	if ( 0 < rex_nested_form.totall_nest ) {
		if (!regular_expression_atom_nested_matching()) {
			_regular_expressions_atom_table_destroy () ;
			_string_destroy( &regular_expressions ) ;
			_string_destroy( &object_string ) ;
			_string_destroy( &pattern_elements_matched ) ;
			ReecNestedFormAtomDestroy (&rex_nested_form) ;
			return 0 ;
		}
		
	} else {
		if (!regular_expression_atom_matching_begin()) {
			_regular_expressions_atom_table_destroy () ;
			_string_destroy( &regular_expressions ) ;
			_string_destroy( &object_string ) ;
			_string_destroy( &pattern_elements_matched ) ;
			ReecNestedFormAtomDestroy (&rex_nested_form) ;
			return 0 ;
		}
	}

	_regular_expressions_atom_table_destroy () ;
	_string_destroy( &regular_expressions ) ;
	_string_destroy( &object_string ) ;
	ReecNestedFormAtomDestroy (&rex_nested_form) ;
	
	_string_add( &pattern_elements_matched , '\0' ) ;

# ifdef REEC_BENCHMARK
	rexetime = clock () ;
	printf ( "Rex Decoding Cost : %d\n" , rexetime-rexstime ) ;
# endif

	return pattern_elements_matched.data ;

}

# if 0 
int TOKRegularExpressionEnginePositionRun( char* regular_expression , char* string , int level ) {
	
	//	author: Jelo Wang
	//	since : 20091120
	//	(C)TOK	

	int position = -1 ;

	if ( !regular_expression || !string )
		return 0 ;
	
	reecmonitor.rs_level = level ;

	_string_destroy( &pattern_elements_matched ) ;
	_regular_expressions_atom_table_initialize () ;

	_string_initialize( &regular_expressions , regular_expression ) ;
	_string_initialize( &object_string , string ) ;
	_string_initialize_with_length( &pattern_elements_matched , strlen(string) + 1 ) ;
	
	if ( 0 == regular_expression_atom_analyze () ) {
		_regular_expressions_atom_table_destroy () ;
		_string_destroy( &regular_expressions ) ;
		_string_destroy( &object_string ) ;
		_string_destroy( &pattern_elements_matched ) ;
		ReecNestedFormAtomDestroy (&rex_nested_form) ;
		return 0 ;
	}		

	if (!regular_expression_atom_matching_begin()) {
		_regular_expressions_atom_table_destroy () ;
		_string_destroy( &regular_expressions ) ;
		_string_destroy( &object_string ) ;
		_string_destroy( &pattern_elements_matched ) ;
		ReecNestedFormAtomDestroy (&rex_nested_form) ;
		return 0 ;
	}
	
	position = object_string.walker ;

	_regular_expressions_atom_table_destroy () ;
	_string_destroy( &regular_expressions ) ;
	_string_destroy( &object_string ) ;
	ReecNestedFormAtomDestroy (&rex_nested_form) ;

	_string_add( &pattern_elements_matched , '\0' ) ;

	return position ;

}
# endif

void TOKRegularExpressionEngineDestroy() {

	//	author: Jelo Wang
	//	since : 20090530
	//	(C)TOK	

	_string_destroy( &pattern_elements_matched ) ;

}

