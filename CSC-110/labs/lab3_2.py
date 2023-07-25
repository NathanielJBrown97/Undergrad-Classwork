# Nathaniel Brown 
stocks = ['IBM','AAPL','GOOG','FB','SMSN','INTC','MCD','TWTR']
stockPrices = [23.4,24.5,25.3,56.7,89.4,45.3,43.6,67.4]
chosenName = input("Enter the name of the stock: ")
percentChange = int(input(("Enter the percentage increase: ")))

if chosenName in stocks:
    

    percentChange2 = percentChange / 100
    priceLocation = stocks.index(chosenName)

    percent = (stockPrices[priceLocation] * percentChange2) + stockPrices[priceLocation]

    stockPrices[priceLocation] = percent
    print("Updated Price List:")
    print(stockPrices)
else:
    print("Stock not found")




