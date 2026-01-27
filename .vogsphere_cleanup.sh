git branch -D vogsphere
git checkout -b vogsphere

make fclean
make -C ./libft fclean

rm -rf *test*
rm -rf *Test*
rm -rf a.out*

rm -rf *.txt
rm -rf .*.txt
rm -rf *.txt

rm -rf .blackmagic.sh
rm -rf .gdb.gdb
rm -rf .gitignore
rm -rf .gitmodules
rm -rf .todo.txt
rm -rf .vogsphere_cleanup.sh
rm -rf .whitemagic.sh

# [make libft files accessible]
git rm --cached libft
cd libft || exit
rm -rf .git
cd ..
git add libft


git add .
git commit -m "auto delete"
git push -f 42 vogsphere:main
git checkout main
git submodule update
