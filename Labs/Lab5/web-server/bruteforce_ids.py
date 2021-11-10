import requests

MAX_ID = 100000000

for i in range(MAX_ID):
	params = {'id': i}
	resp = requests.get('http://141.85.224.119/index.php', params).text

	if 'Unable to find product with ID' not in resp:
		print(f'ID = {i}:')
		print(resp)
		print('\n\n')
