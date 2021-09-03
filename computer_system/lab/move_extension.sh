read -p 'path of folder: ' path
cd $path
file_list=( $( ls -p | grep -v /) )
for FILE in "${file_list[@]}" ; do
mkdir -p "${FILE##*.}" 
mv $FILE "${FILE##*.}"
done

