#if !defined(errors_csq_h)
#define errors_csq_h

    #include "str.h"
    //This function will show error
    void error(str err){
        printf("\033[31m%s %s ","Traceback:\n \t \033[0m",err.Str);
        exit(EXIT_FAILURE);
    }

    namespace csq_error{
        class SyntaxError{
            public:
                int line;
                str text;
                SyntaxError(int line,str text = "Syntax error at line "){this->line = line;this->text = text;}
                void geterror(){
                    error(text+to_str(line));
                }
        };
        class ImportError{
            public:
                str filename;
                void geterror(){
                    error(str("ImportError file ")+filename+" doesn't exists\n");
                }
        };
    }

    void raise(csq_error::SyntaxError se){
        se.geterror();
    }
    void raise(csq_error::ImportError ie){
        ie.geterror();
    }

#endif // errors_csq_h
