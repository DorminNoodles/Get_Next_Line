CLANG(1)                             Clang                            CLANG(1)



NNAAMMEE
       clang - the Clang C, C++, and Objective-C compiler

SSYYNNOOPPSSIISS
       ccllaanngg [_o_p_t_i_o_n_s] _f_i_l_e_n_a_m_e _._._.

DDEESSCCRRIIPPTTIIOONN
       ccllaanngg  is  a C, C++, and Objective-C compiler which encompasses prepro-
       cessing, parsing, optimization, code generation, assembly, and linking.
       Depending  on  which high-level mode setting is passed, Clang will stop
       before doing a full link.  While Clang  is  highly  integrated,  it  is
       important to understand the stages of compilation, to understand how to
       invoke it.  These stages are:

       DDrriivveerr The clang executable is actually a small driver  which  controls
              the  overall  execution  of  other  tools  such as the compiler,
              assembler and linker.  Typically you do  not  need  to  interact
              with  the  driver, but you transparently use it to run the other
              tools.

       PPrreepprroocceessssiinngg
              This stage handles tokenization of the input source file,  macro
              expansion, #include expansion and handling of other preprocessor
              directives.  The output of this stage is typically called a ".i"
              (for  C),  ".ii"  (for  C++), ".mi" (for Objective-C), or ".mii"
              (for Objective-C++) file.

       PPaarrssiinngg aanndd SSeemmaannttiicc AAnnaallyyssiiss
              This stage  parses  the  input  file,  translating  preprocessor
              tokens  into a parse tree.  Once in the form of a parse tree, it
              applies semantic analysis to compute types  for  expressions  as
              well  and  determine whether the code is well formed. This stage
              is responsible for generating most of the compiler  warnings  as
              well  as  parse errors. The output of this stage is an "Abstract
              Syntax Tree" (AST).

       CCooddee GGeenneerraattiioonn aanndd OOppttiimmiizzaattiioonn
              This stage translates an AST into  low-level  intermediate  code
              (known as "LLVM IR") and ultimately to machine code.  This phase
              is responsible for optimizing the generated  code  and  handling
              target-specific  code  generation.   The output of this stage is
              typically called a ".s" file or "assembly" file.

              Clang also supports the use of an integrated assembler, in which
              the  code  generator produces object files directly. This avoids
              the overhead of generating the ".s" file and of calling the tar-
              get assembler.

       AAsssseemmbblleerr
              This  stage runs the target assembler to translate the output of
              the compiler into a target object file. The output of this stage
              is typically called a ".o" file or "object" file.

       LLiinnkkeerr This stage runs the target linker to merge multiple object files
              into an executable or dynamic library. The output of this  stage
              is typically called an "a.out", ".dylib" or ".so" file.

       CCllaanngg SSttaattiicc AAnnaallyyzzeerr

       The  Clang  Static  Analyzer is a tool that scans source code to try to
       find bugs through code analysis.  This tool uses many  parts  of  Clang
       and    is    built    into    the   same   driver.    Please   see   <-
       _h_t_t_p_:_/_/_c_l_a_n_g_-_a_n_a_l_y_z_e_r_._l_l_v_m_._o_r_g> for more details  on  how  to  use  the
       static analyzer.

OOPPTTIIOONNSS
   SSttaaggee SSeelleeccttiioonn OOppttiioonnss
       --EE     Run the preprocessor stage.

       --ffssyynnttaaxx--oonnllyy
              Run the preprocessor, parser and type checking stages.

       --SS     Run the previous stages as well as LLVM generation and optimiza-
              tion stages and target-specific code  generation,  producing  an
              assembly file.

       --cc     Run  all  of  the above, plus the assembler, generating a target
              ".o" object file.

       nnoo ssttaaggee sseelleeccttiioonn ooppttiioonn
              If no stage selection option is specified, all stages above  are
              run,  and  the linker is run to combine the results into an exe-
              cutable or shared library.

   LLaanngguuaaggee SSeelleeccttiioonn aanndd MMooddee OOppttiioonnss
       --xx <<llaanngguuaaggee>>
              Treat subsequent input files as having type language.

       --ssttdd==<<llaanngguuaaggee>>
              Specify the language standard to compile for.

       --ssttddlliibb==<<lliibbrraarryy>>
              Specify the C++ standard library to use; supported  options  are
              libstdc++ and libc++.

       --aannssii  Same as -std=c89.

       --OObbjjCC,, --OObbjjCC++++
              Treat  source  input  files as Objective-C and Object-C++ inputs
              respectively.

       --ttrriiggrraapphhss
              Enable trigraphs.

       --ffffrreeeessttaannddiinngg
              Indicate that the file should be compiled  for  a  freestanding,
              not a hosted, environment.

       --ffnnoo--bbuuiillttiinn
              Disable  special handling and optimizations of builtin functions
              like ssttrrlleenn(()) and mmaalllloocc(()).

       --ffmmaatthh--eerrrrnnoo
              Indicate that math  functions  should  be  treated  as  updating
              eerrrrnnoo.

       --ffppaassccaall--ssttrriinnggss
              Enable support for Pascal-style strings with "\pfoo".

       --ffmmss--eexxtteennssiioonnss
              Enable support for Microsoft extensions.

       --ffmmsscc--vveerrssiioonn==
              Set _MSC_VER. Defaults to 1300 on Windows. Not set otherwise.

       --ffbboorrllaanndd--eexxtteennssiioonnss
              Enable support for Borland extensions.

       --ffwwrriittaabbllee--ssttrriinnggss
              Make  all  string  literals  default to writable.  This disables
              uniquing of strings and other optimizations.

       --ffllaaxx--vveeccttoorr--ccoonnvveerrssiioonnss
              Allow loose type checking rules for implicit vector conversions.

       --ffbblloocckkss
              Enable the "Blocks" language feature.

       --ffoobbjjcc--ggcc--oonnllyy
              Indicate  that  Objective-C  code  should be compiled in GC-only
              mode, which only works when Objective-C  Garbage  Collection  is
              enabled.

       --ffoobbjjcc--ggcc
              Indicate  that  Objective-C code should be compiled in hybrid-GC
              mode, which works with both GC and non-GC mode.

       --ffoobbjjcc--aabbii--vveerrssiioonn==vveerrssiioonn
              Select the Objective-C ABI version to  use.  Available  versions
              are  1  (legacy  "fragile"  ABI),  2  (non-fragile ABI 1), and 3
              (non-fragile ABI 2).

       --ffoobbjjcc--nnoonnffrraaggiillee--aabbii--vveerrssiioonn==<<vveerrssiioonn>>
              Select  the  Objective-C  non-fragile  ABI  version  to  use  by
              default.  This will only be used as the Objective-C ABI when the
              non-fragile ABI is enabled (either via _-_f_o_b_j_c_-_n_o_n_f_r_a_g_i_l_e_-_a_b_i, or
              because it is the platform default).

       --ffoobbjjcc--nnoonnffrraaggiillee--aabbii,, --ffnnoo--oobbjjcc--nnoonnffrraaggiillee--aabbii
              Enable  use of the Objective-C non-fragile ABI. On platforms for
              which  this  is  the  default  ABI,  it  can  be  disabled  with
              _-_f_n_o_-_o_b_j_c_-_n_o_n_f_r_a_g_i_l_e_-_a_b_i.

   TTaarrggeett SSeelleeccttiioonn OOppttiioonnss
       Clang  fully  supports  cross  compilation  as  an inherent part of its
       design.  Depending on how your version of Clang is configured,  it  may
       have  support  for  a  number of cross compilers, or may only support a
       native target.

       --aarrcchh <<aarrcchhiitteeccttuurree>>
              Specify the architecture to build for.

       --mmmmaaccoossxx--vveerrssiioonn--mmiinn==<<vveerrssiioonn>>
              When building for Mac OS X, specify  the  minimum  version  sup-
              ported by your application.

       --mmiipphhoonneeooss--vveerrssiioonn--mmiinn
              When  building  for  iPhone OS, specify the minimum version sup-
              ported by your application.

       --mmaarrcchh==<<ccppuu>>
              Specify that Clang should generate code for a specific processor
              family   member   and   later.   For  example,  if  you  specify
              -march=i486, the compiler is allowed  to  generate  instructions
              that  are  valid on i486 and later processors, but which may not
              exist on earlier ones.

   CCooddee GGeenneerraattiioonn OOppttiioonnss
       --OO00,, --OO11,, --OO22,, --OO33,, --OOffaasstt,, --OOss,, --OOzz,, --OO,, --OO44
              Specify which optimization level to use:
                 _-_O_0 Means "no optimization": this level compiles the  fastest
                 and generates the most debuggable code.

                 _-_O_1 Somewhere between _-_O_0 and _-_O_2.

                 _-_O_2  Moderate  level of optimization which enables most opti-
                 mizations.

                 _-_O_3 Like _-_O_2, except that it enables optimizations that  take
                 longer  to  perform  or  that may generate larger code (in an
                 attempt to make the program run faster).

                 _-_O_f_a_s_t Enables all the  optimizations  from  _-_O_3  along  with
                 other  aggressive  optimizations that may violate strict com-
                 pliance with language standards.

                 _-_O_s Like _-_O_2 with extra optimizations to reduce code size.

                 _-_O_z Like _-_O_s (and thus _-_O_2), but reduces code size further.

                 _-_O Equivalent to _-_O_2.

                 _-_O_4 and higher
                     Currently equivalent to _-_O_3

       --gg,, --gglliinnee--ttaabblleess--oonnllyy,, --ggmmoodduulleess
              Control debug information output.  Note that Clang debug  infor-
              mation  works  best  at _-_O_0.  When more than one option starting
              with _-_g is specified, the last one wins:
                 --gg Generate debug information.

                 --gglliinnee--ttaabblleess--oonnllyy Generate only line  table  debug  informa-
                 tion.  This  allows for symbolicated backtraces with inlining
                 information, but does not include any information about vari-
                 ables, their locations or types.

                 _-_g_m_o_d_u_l_e_s  Generate  debug information that contains external
                 references to types defined in Clang modules  or  precompiled
                 headers  instead of emitting redundant debug type information
                 into every object file.  This option  transparently  switches
                 the  Clang  module format to object file containers that hold
                 the Clang module together with the debug  information.   When
                 compiling  a  program  that uses Clang modules or precompiled
                 headers, this option produces complete debug information with
                 faster compile times and much smaller object files.

                 This option should not be used when building static libraries
                 for distribution to other machines  because  the  debug  info
                 will  contain  references  to the module cache on the machine
                 the object files in the library were built on.

       --ffssttaannddaalloonnee--ddeebbuugg --ffnnoo--ssttaannddaalloonnee--ddeebbuugg
              Clang supports a number of optimizations to reduce the  size  of
              debug  information in the binary. They work based on the assump-
              tion that the debug type information can be spread out over mul-
              tiple compilation units.  For instance, Clang will not emit type
              definitions for types that are not needed by a module and  could
              be  replaced  with  a  forward declaration.  Further, Clang will
              only emit type info for a dynamic C++ class in the  module  that
              contains the vtable for the class.

              The  --ffssttaannddaalloonnee--ddeebbuugg  option  turns  off these optimizations.
              This is useful when working with 3rd-party libraries that  don't
              come  with  debug  information.   This is the default on Darwin.
              Note that Clang will never emit type information for types  that
              are not referenced at all by the program.

       --ffeexxcceeppttiioonnss
              Enable  generation of unwind information. This allows exceptions
              to be thrown through Clang compiled stack frames.  This is on by
              default in x86-64.

       --ffttrraappvv
              Generate  code to catch integer overflow errors.  Signed integer
              overflow is undefined in C. With this flag, extra code is gener-
              ated to detect this and abort when it happens.

       --ffvviissiibbiilliittyy
              This flag sets the default visibility level.

       --ffccoommmmoonn,, --ffnnoo--ccoommmmoonn
              This flag specifies that variables without initializers get com-
              mon linkage.  It can be disabled with _-_f_n_o_-_c_o_m_m_o_n.

       --ffttllss--mmooddeell==<<mmooddeell>>
              Set the default thread-local storage  (TLS)  model  to  use  for
              thread-local  variables.  Valid  values  are:  "global-dynamic",
              "local-dynamic", "initial-exec" and "local-exec". The default is
              "global-dynamic".  The  default model can be overridden with the
              tls_model attribute. The compiler will  try  to  choose  a  more
              efficient model if possible.

       --ffllttoo,, --eemmiitt--llllvvmm
              Generate  output  files  in LLVM formats, suitable for link time
              optimization.  When used with _-_S this generates LLVM  intermedi-
              ate  language assembly files, otherwise this generates LLVM bit-
              code format object files (which may  be  passed  to  the  linker
              depending on the stage selection options).

   DDrriivveerr OOppttiioonnss
       --######   Print (but do not run) the commands to run for this compilation.

       ----hheellpp Display available options.

       --QQuunnuusseedd--aarrgguummeennttss
              Do not emit any warnings for unused driver arguments.

       --WWaa,,<<aarrggss>>
              Pass the comma separated arguments in args to the assembler.

       --WWll,,<<aarrggss>>
              Pass the comma separated arguments in args to the linker.

       --WWpp,,<<aarrggss>>
              Pass the comma separated arguments in args to the  preprocessor.

       --XXaannaallyyzzeerr <<aarrgg>>
              Pass arg to the static analyzer.

       --XXaasssseemmbblleerr <<aarrgg>>
              Pass arg to the assembler.

       --XXlliinnkkeerr <<aarrgg>>
              Pass arg to the linker.

       --XXpprreepprroocceessssoorr <<aarrgg>>
              Pass arg to the preprocessor.

       --oo <<ffiillee>>
              Write output to file.

       --pprriinntt--ffiillee--nnaammee==<<ffiillee>>
              Print the full library path of file.

       --pprriinntt--lliibbggcccc--ffiillee--nnaammee
              Print the library path for "libgcc.a".

       --pprriinntt--pprroogg--nnaammee==<<nnaammee>>
              Print the full program path of name.

       --pprriinntt--sseeaarrcchh--ddiirrss
              Print the paths used for finding libraries and programs.

       --ssaavvee--tteemmppss
              Save intermediate compilation results.

       --iinntteeggrraatteedd--aass,, --nnoo--iinntteeggrraatteedd--aass
              Used  to  enable and disable, respectively, the use of the inte-
              grated assembler. Whether the  integrated  assembler  is  on  by
              default is target dependent.

       --ttiimmee  Time individual commands.

       --ffttiimmee--rreeppoorrtt
              Print timing summary of each stage of compilation.

       --vv     Show commands to run and use verbose output.

   DDiiaaggnnoossttiiccss OOppttiioonnss
       --ffsshhooww--ccoolluummnn,,  --ffsshhooww--ssoouurrccee--llooccaattiioonn,, --ffccaarreett--ddiiaaggnnoossttiiccss,, --ffddiiaaggnnooss--
       ttiiccss--ffiixxiitt--iinnffoo,,       --ffddiiaaggnnoossttiiccss--ppaarrsseeaabbllee--ffiixxiittss,,       --ffddiiaaggnnooss--
       ttiiccss--pprriinntt--ssoouurrccee--rraannggee--iinnffoo,,   --ffpprriinntt--ssoouurrccee--rraannggee--iinnffoo,,   --ffddiiaaggnnooss--
       ttiiccss--sshhooww--ooppttiioonn,, --ffmmeessssaaggee--lleennggtthh
              These  options  control  how  Clang prints out information about
              diagnostics (errors and warnings). Please see the  Clang  User's
              Manual for more information.

   PPrreepprroocceessssoorr OOppttiioonnss
       --DD<<mmaaccrroonnaammee>>==<<vvaalluuee>>
              Adds  an  implicit  #define  into the predefines buffer which is
              read before the source file is preprocessed.

       --UU<<mmaaccrroonnaammee>>
              Adds an implicit #undef into the predefines buffer which is read
              before the source file is preprocessed.

       --iinncclluuddee <<ffiilleennaammee>>
              Adds  an  implicit  #include into the predefines buffer which is
              read before the source file is preprocessed.

       --II<<ddiirreeccttoorryy>>
              Add the specified directory  to  the  search  path  for  include
              files.

       --FF<<ddiirreeccttoorryy>>
              Add  the  specified  directory  to the search path for framework
              include files.

       --nnoossttddiinncc
              Do not  search  the  standard  system  directories  or  compiler
              builtin directories for include files.

       --nnoossttddlliibbiinncc
              Do not search the standard system directories for include files,
              but do search compiler builtin include directories.

       --nnoobbuuiillttiinniinncc
              Do not search clang's builtin directory for include files.

EENNVVIIRROONNMMEENNTT
       TTMMPPDDIIRR,, TTEEMMPP,, TTMMPP
              These environment variables are checked, in order, for the loca-
              tion  to  write  temporary  files  used  during  the compilation
              process.

       CCPPAATTHH  If this environment variable is present,  it  is  treated  as  a
              delimited  list  of  paths  to  be  added  to the default system
              include path list.  The  delimiter  is  the  platform  dependent
              delimiter, as used in the PATH environment variable.

              Empty components in the environment variable are ignored.

       CC__IINNCCLLUUDDEE__PPAATTHH,,     OOBBJJCC__IINNCCLLUUDDEE__PPAATTHH,,     CCPPLLUUSS__IINNCCLLUUDDEE__PPAATTHH,,    OOBBJJCC--
       PPLLUUSS__IINNCCLLUUDDEE__PPAATTHH
              These  environment  variables  specify  additional paths, as for
              _C_P_A_T_H, which are only used when processing the appropriate  lan-
              guage.

       MMAACCOOSSXX__DDEEPPLLOOYYMMEENNTT__TTAARRGGEETT
              If  _-_m_m_a_c_o_s_x_-_v_e_r_s_i_o_n_-_m_i_n  is unspecified, the default deployment
              target is read from this environment variable. This option  only
              affects Darwin targets.

BBUUGGSS
       To report bugs, please visit <_h_t_t_p_:_/_/_l_l_v_m_._o_r_g_/_b_u_g_s_/>.  Most bug reports
       should include preprocessed source files (use the _-_E  option)  and  the
       full output of the compiler, along with information to reproduce.

SSEEEE AALLSSOO
       _a_s_(_1_), _l_d_(_1_)

AAUUTTHHOORR
       Maintained by the Clang / LLVM Team (<http://clang.llvm.org>)

CCOOPPYYRRIIGGHHTT
       2007-2016, The Clang Team



clang-800                      October 02, 2016                       CLANG(1)
