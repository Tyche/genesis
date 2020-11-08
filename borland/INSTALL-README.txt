Installation instructions for Embarcadero C++ Buidler 10.3 Community Edition for Windws 10

Required software:
 Embarcadero C++ 10.3 compiler - see https://www.embarcadero.com/products/cbuilder/starter
 Yacc - see http://gnuwin32.sourceforge.net/packages/byacc.htm

Instructions:

1) Install yacc - the yacc.exe should be in the path or placed in this directory
2) switch to this directory 
   ex. cd C:\genesis\borland
   Note: This directory must be installed under the Genesis distribution directory
3) run the configure batch file
   configure
4) run the parse batch file to build the parser with yacc
   parse
5) Open the genesis-coldc.groupproj file in Embarcadero Builder
6) Select "build all projects" on the Project tab
7) The executables will be found in the ..\borland\Debug\Win32 directory 

The support scripts cannot be executed unless you install a Windows version of Perl, like
ActiveState Perl.

11/07/20
Jon Lambert 
   

===================================================================================

Installation instructions for Windows NT/2K/XP using the Borland C++ v5.5 compiler.

Required software:
 Borland C++ v5.5 compiler - see http://www.borland.com/bcppbuilder/freecompiler/
 Yacc - see http://gnuwin32.sourceforge.net/packages/byacc.htm

Instructions:

1) Install the Borland C++ compiler and configure it.  Instructions for configuring
   the compiler are found in the readme.txt file in the BCCROOT directory.  While 
   the make file is explicit, the Borland compiler bin directory must be in the
   path.  Be sure that Borland's make.exe is invoked and not some other make utility.
2) Install yacc - the yacc.exe should be in the path or placed in this directory
3) switch to this directory 
   ex. cd C:\Genesis-1.1.11-STABLE\borland
   Note: This directory must be installed under the Genesis distribution directory
4) run the configure batch file
   configure
5) run make
   make
   
Additional Make options:
 make clean - deletes all the products of compilation and linking
 make cleanconfig - deletes all the products of configure.bat script
 make -DINSTDIR=<dir> install - will install the executables and the perl scripts
   in the distribution bin directory to the named installation directory, 
   (i.e. make -DINSTDIR=C:\ColdCore-3.1 install)
 make test - will run the regression tests.  
   On failure a 'runtests.log' file will be created.  You'll have to manually determine 
   which test failed by examining it and the 'expected' and 'output' files.
 
By default the products of make are dynamic linked to the RTL and contain no debugging 
information.  However several other options are available:
 make -DSTATIC          produces static linked with no debugging information.
 make -DDEBUG           produces dynamic linked with debugging information.
 make -DDEBUG -DSTATIC  produces static linked with debugging information.

 Use Borland TurboDebugger for debugging (also available at the above mentioned web site)

Berkeley dbm 1.85 is included in this distribution for convenience.  It only includes
those portions required to implement ndbm.  If you wish to instead link against other 
versions of Berkely dbm's or Gnu's gdbm modify the makefile accordingly.

The support scripts cannot be executed unless you install a Windows version of Perl, like
ActiveState Perl.

01/04/03
Jon Lambert 

   
