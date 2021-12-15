set xlabel "iteration"
set ylabel "loss-cross-entropy"
set title "Loss-CrossEntropy"
plot "./data/loss_class_relu" using 2:5 title "loss-python-relu" w l
replot "./data/loss_class_sigmoid" using 2:5 title "loss-python-sigmoid" w l
replot "./data/loss_class_tanh" using 2:5 title "loss-python-tanh" w l
replot "./data/loss_class_relu_c" using 1:2 title "loss-c-relu-modified" w l
replot "./data/loss_class_sigmoid_c" using 1:2 title "loss-c-sigmoid" w l
replot "./data/loss_class_tanh_c" using 1:2 title "loss-c-tanh" w l
pause -1 "Hit"
