set xlabel "iteration"
set ylabel "loss-MSE"
set title "Loss-MSE"
plot "./data/mse_class_sigmoid" using 2:5 title "loss-python-sigmoid" w l
replot "./data/mse_class_tanh" using 2:5 title "loss-python-tanh" w l
replot "./data/mse_class_relu_c" using 1:2 title "loss-c-relu-modified" w l
replot "./data/mse_class_sigmoid_c" using 1:2 title "loss-c-sigmoid" w l
replot "./data/mse_class_tanh_c" using 1:2 title "loss-c-tanh" w l
pause -1 "Hit"
