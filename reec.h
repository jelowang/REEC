

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

# include "rex.h"

# ifdef __CPLUSCPLUS_USED__
	
	extern "C" int TOKRegularExpressionEngineBooleanRun ( char* regular_expression , char* string , int level ) ;
	extern "C" char* TOKRegularExpressionEngineRun ( char* regular_expression , char* string , int level ) ;
	extern "C" int TOKRegularExpressionEnginePositionRun( char* regular_expression , char* string , int level ) ;
	extern "C" void TOKRegularExpressionEngineDestroy () ;
	
# else

	int TOKRegularExpressionEngineBooleanRun ( char* regular_expression , char* string , int level ) ;
	char* TOKRegularExpressionEngineRun ( char* regular_expression , char* string , int level ) ;
	int TOKRegularExpressionEnginePositionRun( char* regular_expression , char* string , int level ) ;
	void TOKRegularExpressionEngineDestroy () ;
	
# endif

