from sklearn.neural_network import MLPClassifier as MLP
from sklearn.model_selection import train_test_split as TTS
import pandas as p
dat=p.read_csv('/home/baadalvm/CLionProjects/Lab4/Lab4_IDE/Neural/data.csv')
x=dat.values
y=dat.values
X=x[:,2:32]
Y=y[:,1]
trax,tesx,tray,tesy=TTS(X,Y,test_size=0.20,shuffle=False)
mlp= MLP(solver='sgd',verbose=True,hidden_layer_sizes=(30,30,30),activation='tanh',max_iter=200,shuffle=False,alpha=0.0001,learning_rate_init=0.001,learning_rate='constant')
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

