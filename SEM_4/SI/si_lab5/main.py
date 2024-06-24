import nltk
from wordcloud import WordCloud
import matplotlib.pyplot as plt
import stopwordsiso as stopwords

nltk.download('punkt')
polish_stopwords = stopwords.stopwords("pl")#set polish stopwords

with open('opowiesc_wigilijna.txt', 'r', encoding='utf-8') as file:#Reading form .txt file
    text = file.read()

#Adding words to wordcloud
words = nltk.word_tokenize(text)
cleaned_text = ' '.join(word for word in words if word.lower() not in polish_stopwords and word.isalnum())

wordcloud = WordCloud(width=800, height=400, background_color='white').generate(cleaned_text)#Generating wordcloud

#Displaying wordcloud
plt.figure(figsize=(10, 5))
plt.imshow(wordcloud, interpolation='bilinear')
plt.axis('off')
plt.show()
