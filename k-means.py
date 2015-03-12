from random import randint

data = open('cancer.txt')
genes = []
k = int(input())
data_list = []

for line in data:
    cur_line = line.split('\t')
    if cur_line[3] == 'NA':
        continue
    else:
        genes.append(cur_line[3])
        for i in range(4, len(cur_line)):
            data_list.append([float(cur_line[i])])
        break

for line in data:
    cur_line = line.split('\t')
    if cur_line[3] == 'NA':
        continue
    else:
        genes.append(cur_line[3])
        for i in range(4, len(cur_line)):
            data_list[i - 4].append(float(cur_line[i]))

print("data is read", end = '\n')

def random_centers(data):
    centers = []
    for i in range(k):
        while (True):
            new_center = randint(0, len(data) - 1)
            if data[new_center] not in centers:
                centers.append(data[new_center])
                break
        #print(centers, end = '\n')
    return centers
        
def distance(point1, point2):
    dist = 0
    for coord in range(len(point1)):
        dist += (point1[coord] - point2[coord])**2
    dist = dist**(1/2)
    return dist

def search_centers(data, centers):
    clasters = [[i] for i in centers]
    for point in range(len(data)):
        cur_dist = distance(data[point], centers[0])
        cur_center = 0
        for center in range(len(centers)):
            if cur_dist > distance(data[point], centers[center]):
                cur_dist = distance(data[point], centers[center])
                cur_center = center
        clasters[cur_center].append(data[point])
    print('clasters are formed by old centers', end = '\n')
    
    new_centers = []
    for claster in clasters:
        new_center = []
        for coord in range(len(claster[0])):
            cur_center_coord = 0
            for point in claster:
                cur_center_coord += point[coord]
            cur_center_coord /= len(claster)
            cur_center_coord = round(cur_center_coord, 4)
            new_center.append(cur_center_coord)
        new_centers.append(new_center)
    print(new_centers)
    if centers == new_centers:
        return clasters
    else:
        print('False', end = '\n')
        return search_centers(data, new_centers)
    
centers = random_centers(data_list)
print('random centers are filled', end = '\n')
clasters = search_centers(data_list, centers)

#print(clasters[0][0])
input()