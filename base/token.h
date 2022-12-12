#if !defined(TOKEN_CSQV3)
#define TOKEN_CSQV3

//Tokens with their meanings  not all are mentioned but defined in seperate functions.
    dict<str,str> tokens{
    {
        "__add__",
        "__gt__",
        "__lt__",
        "__equal__",
        "__assign__",
        "__subt__",
        "__mul__",
        "__div__",
        "__pow__",
        "__powassign__",
        "__brac__",
        "__cbrac__",
        "__gteq__",
        "__lteq__",
        "__noteq__",
        "__addassign__",
        "__subtassign__",
        "__mulassign__",
        "__divassign__",
        "__increment__",
        ":=",
        "#",
    },
    {   
        "auto operator +",
        "auto operator >",
        "auto operator <",
        "auto operator ==",
        "auto operator =",
        "auto operator -",
        "auto operator *",
        "auto operator /",
        "auto operator ^",
        "auto operator ^=",
        "auto operator []",
        "auto operator ()",
        "auto operator >=",
        "auto operator <=",
        "auto operator !=",
        "auto operator+=",
        "auto operator -=",
        "auto operator *=",
        "auto operator /=",
        "auto operator ++",
        "=",
        "//",
    }
    };

    

#endif // TOKEN_CSQV3
