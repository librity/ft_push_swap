# CLONE AND BUILD PROJECT
cd ~
git clone --recurse-submodule https://github.com/librity/ft_push_swap
# git clone 42_INTRA_REPO_ADDRESS ft_push_swap
cd ft_push_swap
# norminette
make norm
make re

# CLONE ALL GITHUB TESTERS
git clone https://github.com/laisarena/push_swap_tester tt_1
git clone https://github.com/LeoFu9487/push_swap_tester tt_2
git clone https://github.com/lmalki-h/push_swap_tester tt_3
git clone https://github.com/minckim42/push_swap_tester tt_4
wget 'https://raw.githubusercontent.com/wwwwelton/push_swap/master/tester.sh' -O vbrazhni.sh && chmod +x vbrazhni.sh
wget 'https://raw.githubusercontent.com/VBrazhnik/Push_swap/master/benchmark.sh' -O wleite.sh && chmod +x wleite.sh

# RUN tt_1
cd tt_1
cp ../push_swap . && bash tester.sh
cd ..

# RUN tt_2
cd tt_2
bash basic_test.sh
cd ..

# RUN tt_3
cd tt_3
bash ./tester.sh .. 100 100

# RUN tt_4
cd tt_4
./push_swap_tester.bash
cd ..
