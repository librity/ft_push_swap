# CLONE AND BUILD PROJECT
cd ~
git clone --recurse-submodule https://github.com/librity/ft_push_swap
# git clone 42_INTRA_REPO_ADDRESS ft_push_swap
cd ft_push_swap
# norminette
make norm
make re

# CLONE GITHUB TESTERS
git clone https://github.com/laisarena/push_swap_tester tt_1
git clone https://github.com/lmalki-h/push_swap_tester tt_2
git clone https://github.com/minckim42/push_swap_tester tt_3
wget 'https://raw.githubusercontent.com/wwwwelton/push_swap/master/tester.sh' -O vbrazhni.sh && chmod +x vbrazhni.sh
wget 'https://raw.githubusercontent.com/VBrazhnik/Push_swap/master/benchmark.sh' -O wleite.sh && chmod +x wleite.sh

# RUN tt_1
cd tt_1
cp ../push_swap . && bash tester.sh

# RUN tt_2
cd ../tt_2
bash ./tester.sh .. 100 100

# RUN tt_3
cd ../tt_3
sed -i -e 's/PUSHSWAP_DIR=..\/push_swap/PUSHSWAP_DIR=../g' push_swap_tester.bash
sed -i -e 's/OS=\"Mac\"/OS=\"linux\"/g' push_swap_tester.bash
./push_swap_tester.bash

# RUN vbrazhni.sh
cd ..
./vbrazhni.sh

# RUN wleite.sh
./wleite.sh
