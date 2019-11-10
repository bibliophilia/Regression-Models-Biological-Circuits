import matplotlib.pyplot as plt
import numpy as np

# Fitting Linear Regression to the dataset
from sklearn.linear_model import LinearRegression
from sklearn.metrics import mean_squared_error

# Fitting Polynomial Regression to the dataset
from sklearn.preprocessing import PolynomialFeatures


# In[4]:


def regression(x, y):
    X = np.array(x).reshape(len(x), 1)
    Y = np.array(y)

    polynomial_features = PolynomialFeatures(degree=5)
    X_polynomial = polynomial_features.fit_transform(X)

    polynomial_features.fit(X_polynomial, Y)
    linear_regression_model_1 = LinearRegression()
    linear_regression_model_1.fit(X_polynomial, Y)
    Y_predict = linear_regression_model_1.predict(X_polynomial)
    rmse1 = np.sqrt(mean_squared_error(Y, Y_predict))

    polynomial_features_2 = PolynomialFeatures(degree=12)
    X_polynomial_2 = polynomial_features_2.fit_transform(X)

    polynomial_features_2.fit(X_polynomial_2, Y)
    linear_regression_model_2 = LinearRegression()
    linear_regression_model_2.fit(X_polynomial_2, y)
    Y_predict_2 = linear_regression_model_2.predict(X_polynomial_2)
    rmse2 = np.sqrt(mean_squared_error(Y, Y_predict_2))

    print(rmse1, rmse2)

    # Visualising the Polynomial Regression results
    plt.scatter(X, Y, color='blue')

    plt.plot(X, Y_predict, color='red')
    plt.plot(X, Y_predict_2, color='yellow')
    plt.title('Polynomial Regression')
    plt.xlabel('Temperature')
    plt.ylabel('Pressure')

    plt.show()
