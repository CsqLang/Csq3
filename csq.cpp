#include "Modules/typing.csqm"
#include "base/code_analysis.h"
//This function will generate IR 
auto IR(str code){
    codeAnalysis ca;
    ca.raw_code = replace_tokens(semicolan_adder(split(code,"\n"))); 
    ca.parse_down();
    return array<array<str>>{ca.imports,ca.functions,ca.code};
}
//This function will compile IR code
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
//This function will run the executable
void run(str current_dir, str name){
    system((str("cd ")+current_dir+str("&& ./")+name + str(" && mv ")+name+str(" ")+name+"so").Str);
}
//This function will write IR code into .csqm file
auto writeIR(str current_dir,str name, str compiler_path){
    auto data = IR(read(current_dir + str("/") + name + ".csq"));
    str total;
    total += "#include \"";
                total += compiler_path + "/Modules/builtins.csqm\"\n";
    for(int i = 0; i < data.len(); i++){
        for(auto ln : data[i]){
            if(i == 0){
                total += replace__import__(ln,current_dir) + "\n";
            }
            else{
                total += replace_meth(replace_class((ln))) + "\n";
            }
            
        }
    }
    write(current_dir + str("/") + name + ".csqm",total);
}
//Driver code
int main(int argc, char const *argv[]){
    
    if(argc < 4){
        printf("Enter 3 arguments: <name> <current-dir> <compiler-path>");
        // abort();
    }
    else{
        writeIR(argv[2],argv[1],argv[3]);
        compile_IR(argv[2],str(argv[2])+str("/")+str(argv[1]) + ".csqm",argv[1]);
        run(argv[2],argv[1]);
    }

        // printf("%s\n", total.Str);
return 0;}
