rm -r Examples build.sh LICENSE README.md 
g++ csq.cpp -o csq &&
g++ mcsq.cpp -o mcsq &&
cd base &&
g++ * &&
cd .. &&
cd Modules/headers &&
g++ * &&
cd ..
