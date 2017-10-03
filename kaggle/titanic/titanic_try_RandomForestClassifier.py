#データの前処理をする部分
import numpy as np
import pandas as pd

train_data = pd.read_csv("./train.csv")
test_data = pd.read_csv("./test.csv")
test_lavel = pd.read_csv("./gender_submission.csv")
train_lavel = train_data.drop((["PassengerId","Pclass","Name","Sex","Age","SibSp","Parch","Ticket","Fare","Cabin","Embarked"]), axis=1)
#print(train_lavel)

train_data = train_data.drop((["PassengerId","Survived","Name","Ticket","Cabin","Embarked"]), axis=1)
Sex_Dummy = pd.get_dummies(train_data["Sex"])
train_data = pd.concat((train_data, Sex_Dummy), axis=1)
train_data = train_data.drop((["Sex", "female"]), axis=1)
Age_ave_train = train_data["Age"].mean()
train_data = train_data.fillna(Age_ave_train)
#print(train_data)

ids = test_data["PassengerId"].values
test_data = test_data.drop((["PassengerId","Name","Ticket","Cabin","Embarked"]), axis=1)
Sex_Dummy = pd.get_dummies(test_data["Sex"])
test_data = pd.concat((test_data, Sex_Dummy), axis=1)
test_data = test_data.drop((["Sex", "female"]), axis=1)
Age_ave_test = test_data["Age"].mean()
test_data = test_data.fillna(Age_ave_test)
#print(test_data)

#test_lavel = test_lavel.drop((["PassengerId"]), axis=1)
#print(test_lavel)

#データを学習させて答え合わせする部分
#解析に使うものによってimportとインスタンス宣言を変える
from sklearn import ensemble

clf = ensemble.RandomForestClassifier()
clf.fit(train_data, train_lavel)
pred = clf.predict(test_data)
#print(pred)

#csvに出力する部分
#解析で使ったものによって出力ファイル名を変える
import csv
submit_file = open("./titanic_submit_RandomForestClassifier.csv", "w")
file_object = csv.writer(submit_file)
file_object.writerow(["PassengerId", "Survived"])
file_object.writerows(zip(ids, pred))
submit_file.close()