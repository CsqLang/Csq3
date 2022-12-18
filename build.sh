mkdir Builds
cp -R * Builds/
cd Builds
rm -r Examples Builds build.sh LICENSE README.md 
g++ csq.cpp -o csq &&
g++ mcsq.cpp -o mcsq &&
cd base &&
g++ * &&
cd .. &&
cd Modules/headers &&
g++ * &&
cd ..
