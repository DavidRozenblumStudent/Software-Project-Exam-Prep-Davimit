import pandas as pd
import numpy as np

def q2(daily_report):
    comp = daily_report.copy()
    comp['Next Day Cases'] = comp['cases'].shift(-1)    

    return comp.loc[comp['Next Day Cases'] > comp['cases'], 'cases'].count()

# Test 
def main():
    days = pd.Series([1,2,3,4,5,6,7,8,9,10])
    cases = pd.Series([200, 584, 293, 201, 100, 300, 200, 425, 354, 700])
    daily_report = pd.DataFrame({'day': days, 'cases': cases})
    print(q2(daily_report))



if __name__ == "__main__":
    main()

