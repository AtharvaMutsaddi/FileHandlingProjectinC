import pandas as pd
import matplotlib.pyplot as plt
db= pd.read_csv("record.csv")
db.sort_values(by=['Score'], inplace=True)
plt.bar(db["Name"], db["Score"])
print(db)
plt.show()