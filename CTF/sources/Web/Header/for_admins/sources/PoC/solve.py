import requests
from datetime import datetime, timedelta
import random

# URL for the Flask application
url = "http://127.0.0.1:5758/flag"

def fixed_datetime_random(datetime_string, start=5000, end=9999):
    dt_object = datetime.strptime(datetime_string, "%Y-%m-%d %H:%M:%S")
    seed_value = int(dt_object.strftime("%Y%m%d%H%M%S"))
    random.seed(seed_value)
    return random.randint(start, end)

# Function to subtract N hours from the current datetime
def get_datetime_minus_n_hours(n):
    current_datetime = datetime.now()  # Get the current datetime
    new_datetime = current_datetime - timedelta(hours=n)  # Subtract N hours
    return new_datetime.strftime("%Y-%m-%d %H:%M:%S")  # Format as string

# Example usage
n = 3  # Number of hours to subtract
current_datetime = get_datetime_minus_n_hours(n)

# Calculate the fixed random integer
random_int = fixed_datetime_random(current_datetime)

# Set headers
headers = {
    "User-Agent": "Windows 98",
    "TimeStamp": current_datetime,
    "RandintStamp": str(random_int)
}

# Send request to the Flask app
response = requests.get(url, headers=headers)

# Print the result
if response.status_code == 200:
    print(response.json())
else:
    print(f"Error: {response.status_code} - {response.json().get('error')}")
