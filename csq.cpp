#include "Modules/typing.csqm"
#include "base/code_analysis.h"
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
    command += " && clang++ -O0 ";
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
    total += "#include \"";
                total += compiler_path + "/Modules/builtins.csqm\"\n";
    for(int i = 0; i < data.len(); i++){
        for(auto ln : data[i]){
            if(i == 0){
                total += replace__import__(ln,current_dir) + "\n";
            }
            else{
                total += (ln) + "\n";
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
        compile_IR(argv[2],str(argv[2])+str("/")+str(argv[1]) + ".csqm",argv[1]);
        run(argv[2],argv[1]);
    }

        // printf("%s\n", total.Str);
return 0;}
