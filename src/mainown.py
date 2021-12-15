from sklearn.neural_network import MLPClassifier as MLP
from sklearn.model_selection import train_test_split as TTS
import pandas as p
dat=p.read_csv('/home/baadalvm/CLionProjects/Lab4/Lab4_IDE/Neural/data2.csv')
x=dat.values
y=dat.values
X=x[:,2:4]
Y=y[:,1]
trax,tesx,tray,tesy=TTS(X,Y,test_size=0.20)
mlp= MLP(solver='sgd',hidden_layer_sizes=(7),activation='logistic',alpha=0.1,learning_rate_init=0.1,max_iter=1000,shuffle=False)
mlp.fit(trax,tray)
print ("Original:")
print(tesy)
pre=mlp.predict(tesx)
prob= mlp.predict_proba(tesx)
print ("Predicted:")
print (pre)
print ("Probability:")
print (prob)
print ("ACCURACY is :")
print ((mlp.score(tesx,tesy))*100)

