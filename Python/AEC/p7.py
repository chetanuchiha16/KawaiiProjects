import seaborn as sns
import matplotlib.pyplot as plt

tips = sns.load_dataset("tips")

sns.set(style = "whitegrid",palette = "deep")

plt.figure(figsize = (8,6))

sns.scatterplot(
    x = "total_bill",
    y="tip",
    data = tips,
    hue = "time",
    style = "sex",s = 100,
    palette = 'dark',
)
plt.title("Customized Scatter plot")
plt.xlabel("Total Bill")
plt.ylabel("TIp")
plt.legend(title = "time of the day")
plt.show()

plt.figure(figsize = (8,6))
sns.histplot(
    tips["total_bill"],
    bins = 20,
    kde  = True,
    color = "skyblue",
    line_kws = {"color":"red"}
)

plt.title("customised Histogram")
plt.xlabel("Total BIll")
plt.ylabel("Frequency")
plt.grid(True)
plt.show()

plt.figure(figsize = (8,6))
sns.boxplot(
    x = "day",y = "total_bill",
    data = tips,
    palette = "husl",
)

plt.title("Customised BOx plot")
plt.xlabel("Day")
plt.ylabel("Total Bill")
plt.show()