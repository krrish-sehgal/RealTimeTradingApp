import matplotlib.pyplot as plt
import pandas as pd

# Load your data from CSV
data = pd.read_csv('../src/stock_data.csv')

# Reverse the order of rows in the DataFrame
data = data[::-1]

# Enable interactive mode
plt.ion()


# Convert the timestamp column to datetime format
data['timestamp'] = pd.to_datetime(data['timestamp'])

# Extract relevant columns
hours = data['timestamp'].dt.strftime('%H:%M')  # Extract only the hour and minute part
closing_prices = data['close']

# Plot the data
plt.plot(hours, closing_prices, marker='o', linestyle='-')


# Customize the plot
plt.xlabel('Timestamp')
plt.ylabel('Closing Price')
plt.title('Stock Prices')

# Adjust spacing between x-axis ticks
plt.xticks(range(0, len(hours), 5))  # Set ticks every 5 data points

# Show the plot
plt.show()

# Wait for user input to close the plot
input("Press Enter to close the plot...")

# Close the plot window
plt.close()
