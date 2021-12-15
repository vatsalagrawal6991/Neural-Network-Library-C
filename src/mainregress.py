from sklearn.neural_network import MLPRegressor as MLP
from sklearn.model_selection import train_test_split as TTS
import pandas as p
dat=p.read_table('/home/baadalvm/CLionProjects/Lab4/Lab4_IDE/Neural/data3.txt',delim_whitespace=True)
x=dat.values
y=dat.values
X=x[:,:12]
Y=y[:,13]

trax,tesx,tray,tesy=TTS(X,Y,test_size=0.20)
mlp= MLP(solver='sgd',verbose=True,hidden_layer_sizes=(30,30,30),activation='tanh',max_iter=200,shuffle=False,alpha=0.0001,learning_rate_init=0.001,learning_rate='constant')
mlp.fit(trax,tray)
print ("Original:")
print(tesy)
pre=mlp.predict(tesx)
print ("Predicted:")
print (pre)
print ("ACCURACY is :")
print ((mlp.score(tesx,tesy))*100)

