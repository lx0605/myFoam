# Installation guide:
## you should already installed OpenFoam
## make sure you have WM_PROJECT_USER_DIR in your environment variable
## make solver and run directories using

mkdir -p $WM_PROJECT_USER_DIR/solvers

mkdir -p $WM_PROJECT_USER_DIR/run

## go to the solver directory

cd $WM_PROJECT_USER_DIR/solvers/

## clone the solver repository

git clone https://github.com/lx0605/myFoam.git

cd singleSoluteIcoFoam

wmake 

cd ../transportPisoFoam

wmake

# you can copy an example (pitzdaily) from OpenFoam into $WM_PROJECT_USER_DIR/run and run the solver

# Thanks!
