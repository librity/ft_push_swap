make re && LIST=$(ruby -e "puts (0..4).to_a.shuffle.join(' ')") && echo $LIST && ./push_swap $LIST
make re && LIST=$(ruby -e "puts (0..4).to_a.shuffle.join(' ')") && echo $LIST && ./push_swap $LIST | ./scripts/checker_linux $LIST
make re && LIST=$(ruby -e "puts (0..4).to_a.shuffle.join(' ')") && echo $LIST && ./push_swap $LIST | wc -l

# laisarena tester
make -C ../.. re && cp ../../push_swap . && bash tester.sh
