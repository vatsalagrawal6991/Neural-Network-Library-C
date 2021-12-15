set xlabel "iteration"
set ylabel "loss-cross-entropy"
set title "Loss-CrossEntropy-For-Back-Propogation-Tanh-100"

plot "./data/sgd_tanh" using 1:2 title "loss-c-tanh-sgd" w l
replot "./data/batch_tanh" using 1:2 title "loss-c-tanh-batch-100" w l
replot "./data/loss_class_tanh_c" using 1:2 title "loss-c-tanh-vanilla" w l
pause -1 "Hit"
