import pandas as pd


data = pd.read_csv("covid_19_data.csv", parse_dates=True)

# print(data.columns)
print(data.plot(kind="bar"))
