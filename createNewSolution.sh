if [ $# != 2 ];then
    echo "请输入要创建的resolution和文件夹"
    exit -1
fi

if [ ! -d $2 ];then
    echo "创建文件价ing"
    mkdir $2 && cd $2
else
    echo "对应文件夹已存在"
    cd $2
fi

if [ ! -f $1 ];then
    echo "创建resolution ing"
    touch $1.h
    echo "#include<header.h>\n" >> $1.h
    echo "class Solution {\n\n" >> $1.h
    echo "}\n" >> $1.h
else
    echo "对应resolution 已存在"
fi
echo "创建完成"