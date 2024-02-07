import numpy as np
import random

# Define constants
N = 16  # Size of the S-box
POPULATION_SIZE = 100
GENERATIONS = 100
MUTATION_RATE = 0.1

# Helper function to calculate nonlinearity
def nonlinearity(s_box):
    max_nonlinearity = 2 ** (N - 1)
    nonlin_values = [0] * N

    for i in range(N):
        for j in range(N):
            delta = i ^ j
            val1 = s_box[i][0] ^ s_box[j][0]  # Assuming 16x16 S-box, comparing only the first column
            val2 = s_box[i ^ delta][0] ^ s_box[j ^ delta][0]
            nonlin_values[delta] = max(
                nonlin_values[delta], abs(val1 - val2)
            )

    return max_nonlinearity - max(nonlinearity for nonlinearity in nonlin_values)

# Helper function to calculate differential uniformity
def differential_uniformity(s_box):
    max_differential_uniformity = N // 2
    diff_unif_values = [0] * N

    for i in range(N):
        for j in range(N):
            delta = i ^ j
            val = s_box[i][0] ^ s_box[j][0]  # Assuming 16x16 S-box, comparing only the first column
            diff_unif_values[delta] += (val == 0)

    return sum(
        (max_differential_uniformity - count) ** 2 for count in diff_unif_values
    )

## Helper function to calculate SAC (Strict Avalanche Criterion)
def sac(s_box):
    max_sac = N // 2
    sac_values = [0] * N

    for i in range(N):
        for j in range(N):
            delta = i ^ j
            val = s_box[i][0] ^ s_box[j][0]  # Assuming 16x16 S-box, comparing only the first column
            sac_values[delta] += (val == 1)

    return sum((max_sac - count) ** 2 for count in sac_values)

# Helper function to calculate BIC (Balancedness Improvement Criterion)
def bic(s_box):
    return abs(2 ** (N - 1) - sum(row[0] for row in s_box))

# Fitness function
def fitness(s_box):
    nonlin = nonlinearity(s_box)
    diff_unif = differential_uniformity(s_box)
    sac_val = sac(s_box)
    bic_val = bic(s_box)

    return nonlin + diff_unif + sac_val + bic_val

# Crossover function
def crossover(parent1, parent2):
    crossover_point = random.randint(1, N - 1)
    child = parent1[:crossover_point] + parent2[crossover_point:]
    return child

# Mutation function
def mutate(individual):
    mutation_point = random.randint(0, N - 1)
    individual[mutation_point] = random.randint(0, 15)  # Limiting the range to [0, 15]
    return individual
def genetic_algorithm():
    s_box = list(range(N**2))  # Initialize with a linear sequence from 0 to N^2 - 1
    random.shuffle(s_box)  # Shuffle the sequence to randomize the S-box
    s_box = np.array(s_box).reshape((N, N))  # Reshape the sequence into a 2D array (S-box)
    
    # Calculate fitness before iterations
    print("Fitness before iterations:", fitness(s_box))
    
    # Perform genetic algorithm iterations
    for generation in range(GENERATIONS):
        # Code for genetic algorithm iterations
        # This part is missing in the provided code
        pass  # Placeholder to ensure the loop is not empty
        
    # Calculate fitness after iterations
    print("Fitness after iterations:", fitness(s_box))
    
    return s_box



# Print the final S-box and its characteristics
final_s_box = genetic_algorithm()
print("Final S-box:")
for row in final_s_box:
    print(row)

# Calculate and print the characteristics
print("Nonlinearity:", nonlinearity(final_s_box))
print("Differential Uniformity:", differential_uniformity(final_s_box))
print("SAC:", sac(final_s_box))
print("BIC:", bic(final_s_box))
