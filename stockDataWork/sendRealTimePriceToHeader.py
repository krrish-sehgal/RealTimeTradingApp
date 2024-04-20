import requests
from bs4 import BeautifulSoup
import sys

def get_realtime_price(ticker, exchange):
    url = f"https://www.google.com/finance/quote/{ticker}:{exchange}"
    response = requests.get(url)    
    soup = BeautifulSoup(response.text, "html.parser")
    price = soup.find("div", class_="YMlKec fxKbKc").text.strip()[1:].replace(",", "")
    return float(price)

if __name__ == "__main__":
    ticker = sys.argv[1]
    exchange = sys.argv[2]
    price = get_realtime_price(ticker, exchange)
    print(price)
