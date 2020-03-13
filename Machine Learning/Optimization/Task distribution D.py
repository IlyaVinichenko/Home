import numpy as np
import random
import matplotlib.pyplot as plt

coefficients = []
mutation_probability = 0.0002
crossbreeding_probability = 0.2
selected_descendants = 25
population = 100
generations = 500
random.seed(20)
tmax = float("inf")

#Genom constist of developers_id
#
#
#

with open("input.txt", 'r') as file:
    N = int(file.readline())
    complexity = list(map(int, file.readline().split()))
    estimate_time = list(map(float, file.readline().split()))
    M = int(file.readline())
    for i in range(M):
        coefficients.append(list(map(float, file.readline().split())))

complexity = np.array(complexity)
estimate_time = np.array(estimate_time)
coefficients = np.array(coefficients)

def mutation(genome):
    new_genome = genome
    for i in range(N):
        if random.random() < mutation_probability:
            new_genome[i] = random.randint(1, M)
    return new_genome

def crossbreeding(genome_x, genome_y):
    if random.random() < crossbreeding_probability:
        for chromosome_id in range(N):
            if random.random() < crossbreeding_probability:
                genome_x[chromosome_id], genome_y[chromosome_id] = genome_y[chromosome_id], genome_x[chromosome_id]
    return mutation(genome_x), mutation(genome_y)

def t(genome):
    for chromosome_id in range(N):
        tmax =  estimate_time[chromosome_id] * coefficients[genome[chromosome_id] - 1][[complexity[chromosome_id] - 1]]

def score(tmax):
    return pow(10, 6) / tmax

#initial birth
genomes = []
for i in range(population):
    genomes.append(np.array([random.randint(1, M)] for chromosome_id in range(N)))
genomes = np.array(genomes)
