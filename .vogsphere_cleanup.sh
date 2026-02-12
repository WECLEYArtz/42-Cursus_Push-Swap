git branch -D vogsphere
git checkout -b vogsphere

make fclean
make -C ./libft fclean

rm -rf \
	*test*\
	*Test*\
	a.out*\
\
	*.txt\
	.*.txt\
	*.txt\
\
	.blackmagic.sh\
	.whitemagic.sh\
	.pinkmagic.sh\
\
	.gdb.gdb\
	.gitignore\
	.gitmodules\
	.todo.txt\
\
	.vogsphere_cleanup.sh

git add .
git commit -m "auto delete"
git push -f 42 vogsphere:main
git checkout main
git submodule update
