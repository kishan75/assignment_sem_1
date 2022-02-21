import uuid
import pyDes
import matplotlib.pyplot as plt


def get_ham_dis(s1, s2):
    assert len(s1) == len(s2)
    return sum(c1 != c2 for c1, c2 in zip(s1, s2))


key = str(uuid.uuid4())[0:8]

data = []
for i in range(6):
    text = str(uuid.uuid4())[0:8]
    cipher = pyDes.des(key)
    cipher.encrypt(text)
    data.append(cipher.rounds)

ham_distances = []
for i in range(16):
    dist = []
    for j in range(5):
        stable = data[5][i]
        round_text = data[j][i]
        dist.append(get_ham_dis(stable, round_text))
    ham_distances.append(dist)

print(ham_distances)

fig = plt.figure()
# Create an axes instance
ax = fig.add_axes([0, 0, 1, 1])
# Create the boxplot
bp = ax.boxplot(ham_distances)
plt.show()

# Press the green button in the gutter to run the script.
if __name__ == '__main__':
    pass
