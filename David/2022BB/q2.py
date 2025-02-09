import numpy as np
import pandas as pd
from faker import Faker


def q2(students):
    '''
    Input: pandas table with columns 'name', 'assignment', 'grade'
    Output: the two students with the biggest difference in their average grades
    '''
    students_avg = students.groupby('name').grade.mean()
    
    return students_avg.sort_values(ascending = False).iloc[0], students_avg.sort_values(ascending = True).iloc[0]


def main():
    fake = Faker()
    names = [fake.name() for i in range(5)] * 3
    assignments = ['Assignment 1', 'Assignment 2', 'Assignment 3'] * 5
    grades = np.random.randint(50, 100, 15)

    students = pd.DataFrame({'name': names, 'assignment': assignments, 'grade': grades})
    print(students)

    max_diff = q2(students)
    print(max_diff[0] - max_diff[1])


if __name__ == "__main__":
    main()