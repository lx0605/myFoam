# Installation guide:
## you should already installed and openFoam
## make sure you have WM_PROJECT_USER_DIR in your environment variable
## make a project user directory using

mkdir -p $WM_PROJECT_USER_DIR/solvers/
mkdir -p $WM_PROJECT_USER_DIR/run

cd $WM_PROJECT_USER_DIR/solvers/
git clone https://github.com/lx0605/myFoam.git

cd singleSoluteIcoFoam
wmake 

cd transportPisoFoam
wmake

# you can copy example in into $WM_PROJECT_USER_DIR/run and run the solver

# Thanks!
