import matplotlib.pyplot as plt
import numpy as np

#Creating data
data_num = 100
X0 = np.random.multivariate_normal([0, 0], [[1, .75], [.75, 1]], data_num)
X1 = np.random.multivariate_normal([1, 4], [[1, .75], [.75, 1]], data_num)
X = np.vstack([X0, X1])
y = np.hstack([np.zeros(data_num), np.ones(data_num)])

#Normalization
X_mean = X.mean(axis=0)
X_std = X.std(axis=0)
X = (X - X_mean) / X_std

class LogisticRegression:
    def __init__(self, learning_rate=0.01, num_iter=1000):
        self.lr = learning_rate
        self.num_iter = num_iter

    def add_intercept(self, X):
        intercept = np.ones((X.shape[0], 1))
        return np.concatenate((intercept, X), axis=1)

    def sigmoid(self, z):
        return 1 / (1 + np.exp(-z))

    def fit(self, X, y):
        X = self.add_intercept(X)
        self.theta = np.zeros(X.shape[1])
        for i in range(self.num_iter):
            z = np.dot(X, self.theta)
            h = self.sigmoid(z)
            gradient = np.dot(X.T, (h - y)) / y.size
            self.theta -= self.lr * gradient

    def predict_prob(self, X):
        X = self.add_intercept(X)
        return self.sigmoid(np.dot(X, self.theta))

    def predict(self, X, threshold=0.5):
        return self.predict_prob(X) >= threshold

#Traing regression model
model = LogisticRegression(learning_rate=0.1, num_iter=3000)
model.fit(X, y)

#MAking plot
plt.figure(figsize=(10, 6))
plt.scatter(X[:, 0], X[:, 1], c=y, cmap='viridis', edgecolor='k')
x1_min, x1_max = X[:, 0].min() - 0.5, X[:, 0].max() + 0.5
x2_min, x2_max = X[:, 1].min() - 0.5, X[:, 1].max() + 0.5
xx1, xx2 = np.meshgrid(np.linspace(x1_min, x1_max, 100), np.linspace(x2_min, x2_max, 100))
grid = np.c_[xx1.ravel(), xx2.ravel()]
probs = model.predict_prob(grid).reshape(xx1.shape)
plt.contourf(xx1, xx2, probs, levels=[0, 0.5, 1], alpha=0.3, colors=['blue', 'orange'])#predictions
plt.contour(xx1, xx2, probs, levels=[0.5], linewidths=1, colors='red')

plt.xlabel('Cecha 1')
plt.ylabel('Cecha 2')
plt.title('Regresja Logistyczna')
plt.show()
