#! /bin/bash


clear

DATA_SUBDIR1="/data/train/input.txt"
DATA_SUBDIR2="/data/train/output.txt"

DATA_DIR1=$PWD$DATA_SUBDIR1
DATA_DIR2=$PWD$DATA_SUBDIR2

# check if the the traiing data is given in folder named -data-
if [ ! -f $DATA_DIR1 ] && [ ! -f $DATA_DIR2 ]; then 
	echo  ' trainign data file does not exist!'
	exit 1
fi
 

# trian mode
if [ $1 == 'train' ]; then
	echo "train mode"
	cmake --build build && ./build/main train
	exit 1
fi




# predict mode
PARA_SUB="/out-train.txt"
PARA_DIR=$PWD$PARA_SUB
echo $PARA_DIR
if [ $1 == 'predict' ]; then
	
	if [ ! -f $PARA_DIR ]; then
		echo "no model has been trained"
		exit 1
	else
		echo "predict mode"
		cmake --build build  && ./build/main predict
		exit 1
	fi
fi

