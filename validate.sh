bash -c 'for lib in `find lib -type d -d 1`; do\
		 	if ! [ -f $lib/Makefile ]; then continue; fi
		 	NAME="libft`echo $lib | sed s/.*ft_//`.a"
		 	if [ -f $lib/$NAME ]; then
		 		make -C $lib $NAME
		 	fi
		 done'
