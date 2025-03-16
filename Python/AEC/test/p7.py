import seaborn as sns
import matplotlib.pyplot as plt

tips = sns.load_dataset('tips')
sns.set(palette = 'deep',style = 'whitegrid')
plt.figure(figsize =(8,6))
sns.scatterplot(x="total_bill",y = "tip",data = tips,style = 'sex', hue = 'time',palette = 'deep')
plt.xlabel('total_bill')
plt.ylabel('tips')
plt.legend(title = 'time of the day')
plt.show()

plt.figure(figsize = (8,6))
sns.histplot(tips["total_bill"], bins = 20,kde = True,line_kws = {'color':'blue'})
plt.title("customized histogram")
plt.xlabel("total_bills")
plt.ylabel("time")
plt.show()

plt.figure(figsize = (8,6))
sns.boxplot(x = 'day',y = 'total_bill',data = tips,palette = 'husl')
plt.title("customized box plot")
plt.xlabel("day")
plt.ylabel("total_bill")
plt.show()