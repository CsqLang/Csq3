 #include "base/str.h"
#include "base/code_analysis2.h"
#include "base/errors.h"
/*
********************For Parser ************************
*/
bool file_exists(const char *filename)
{
    FILE *fp = fopen(filename, "r");
    bool is_exist = false;
    if (fp != NULL)
    {
        is_exist = true;
        fclose(fp); // close the file
    }
    return is_exist;
}
auto import_authe(str ln){
    if(file_exists(ln.Str) == 0){
        csq_error::ImportError ie;
        ie.filename = ln;
        raise(ie);
    }
}
auto __import__(str path){
    // cls += name + "{\n";
    import_authe(path);
    str read_ = read(path,1000000);
    return read_ + "\n";
}
auto replace__import__(str ln,str curr){
    str path = replaceStr(ln.Str,"import ","");
    path = replaceStr(path.Str,".","/");
    str spacesep = replaceStr(path.Str,"/"," ");
    auto splitted = split(spacesep," ");
    str re;
    if(path == splitted[splitted.len()-1]){
        re = curr + "/";
        re += path + ".csqm";
    }
    else{
        re = path + ".csqm";
    }
    // printf("%s \n\n\n\n\n",re.Str);
    return __import__(re);
}
auto replace_for(str ln){
        array<str> words = split(ln," ");
        str nln;
        if(find_str(ln.Str,str("for").Str) == 1 && (find_str(ln.Str,str("for").Str)==1 || find_str(ln.Str,str("for").Str)==1)){
            for(auto w : words){
                if(w == "for"){
                    nln += "for(";
                }
                else if(w == "{" || w == "go"){
                    nln += "){";
                }
                else{
                    nln += w + " ";
                }
            }
        }
        else{
            nln = ln;
        }
        return nln;
    }
auto IR(str code){
    codeAnalysis ca;
    ca.raw_code = replace_tokens(semicolan_adder(split(code,"\n"))); 
    ca.parse_down();
    // str imports;
    // for(auto ln : ca.imports)
    //     imports += replace__import__(ln) + "\n";
    // str functions;
    // for(auto ln : ca.functions)
    
    //     functions += ln + "\n";
    // str codes;
    // for(auto ln : ca.code)
    //     codes += ln + "\n";
    // codes += "\nreturn 0;}";
    return array<array<str>>{ca.imports,ca.functions,ca.code};
}
void compile_IR(str current_path, str path, str name){
    str code = read(path);
    write((current_path+name+".cpp").Str,code);
    str command = "cd ";
    command += current_path;
    command += " && g++ ";
    command += current_path+name+".cpp -o ";
    command += name;
    system(command.Str);
    // system((str("rm ")+current_path+name+".cpp").Str);
}
void run(str current_dir, str name){
    system((str("cd ")+current_dir+str("&& ./")+name + str(" && mv ")+name+str(" ")+name+"so").Str);
}

auto writeIR(str current_dir,str name, str compiler_path){
    auto data = IR(read(current_dir + str("/") + name + ".csq"));
    str total;
    for(int i = 0; i < data.len(); i++){
        for(auto ln : data[i]){
            if(i == 0){
                total += replace__import__(ln,current_dir) + "\n";
            }
            else{
                total += ln + "\n";
            }
            
        }
    }
    write(current_dir + str("/") + name + ".csqm",total);
}

int main(int argc, char const *argv[]){
    
    if(argc < 4){
        printf("Enter 3 arguments: <name> <current-dir> <compiler-path>");
        // abort();
    }
    else{
        writeIR(argv[2],argv[1],argv[3]);
        // compile_IR(argv[2],str(argv[2])+str("/")+str(argv[1]) + ".csqm",argv[1]);

    }

        // printf("%s\n", total.Str);
return 0;}
