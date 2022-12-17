sudo apt install clang && 
clang++ csq.cpp -o csq &&
clang++ mcsq.cpp -o mcsq &&
cd base &&
clang++ * &&
cd .. &&
cd Modules/headers &&
clang++ * &&
cd ..
