# Stock Analysis Program

The Stock Analysis Program is a C program designed to analyze stock data stored in a CSV file. It provides various functionalities such as calculating percentage change in stock prices, sorting stocks by volume and closing price, analyzing profit or loss, determining the highest and lowest performing stocks, calculating overall performance, and finding the average value of all stocks.

## Features

1. **Percentage Change in Stock**
   - Calculate the percentage change in the price of a selected stock between two given dates. This function allows users to track the change in stock prices over time and assess the performance of individual stocks.
     - Function Name: `priceChange()`

2. **Sorting by Volume --> Close Price**
   - Sort stocks based on volume and closing price for a specified date. This function enables users to identify stocks with high trading volume and analyze their closing prices, providing insights into market trends and investor behavior.
     - Function Name: `sortVolumeCloseP()`

3. **Profit or Loss of Stocks**
   - Analyze the profit or loss for each stock between two given dates. By calculating the difference between the high and low prices of a stock within a specific time frame, users can assess the profitability of their investments.
     - Function Name: `profitLoss()`

4. **Highest Performing Stock**
   - Identify the stock with the highest performance (highest gain) between two given dates. This function helps users pinpoint stocks that have experienced significant price increases, potentially indicating strong market performance.
     - Function Name: `performance()`

5. **Lowest Performing Stock**
   - Identify the stock with the lowest performance (least gain) between two given dates. By identifying stocks with minimal price changes or losses, users can make informed decisions about portfolio management and investment strategies.
     - Function Name: `performance()`

6. **Overall Performance**
   - Determine the overall performance of each stock based on volume and price changes over a specified period. This function provides a comprehensive analysis of stock performance, considering both trading volume and price fluctuations.
     - Function Name: `overallPerformance()`

7. **Average Value of All Stocks**
   - Calculate the average value of all stocks for a specified date range. By averaging the closing prices of multiple stocks over time, users can gain insights into the overall market trends and assess the general direction of stock prices.
     - Function Name: `average()`

## Specifications for CSV File

- The CSV file should contain stock data in the following format:
Date,Open,High,Low,Close,Volume

- **Date:** Date of the stock data (e.g., "16/10/23").
- **Open:** Opening price of the stock.
- **High:** Highest price of the stock during the day.
- **Low:** Lowest price of the stock during the day.
- **Close:** Closing price of the stock.
- **Volume:** Volume of stock traded during the day.

- Each row in the CSV file represents the data for one day.

## Usage

1. **Load Data**: The program loads stock data from the provided CSV file.

2. **Menu Selection**: Choose an option from the menu to perform various analyses on the stock data.

3. **Input Dates**: Input dates in "dd" format within the available range (e.g., from 16 to 20) when prompted.

4. **View Results**: View the analysis results based on the selected option.

5. **Exit**: Choose the exit option from the menu to terminate the program.

## Dependencies

- This program requires a C compiler to build and execute.

## Contributions

Contributions to the Stock Analysis Program project are welcome! Whether it's bug fixes, feature enhancements, or documentation improvements, feel free to contribute to make this program even better.
