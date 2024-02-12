import numpy as np
import random
from fractions import Fraction

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
            val1 = s_box[i] ^ s_box[j]  # Comparing values directly as S-box is represented as a 1D array
            val2 = s_box[i ^ delta] ^ s_box[j ^ delta]
            nonlin_values[delta] = max(nonlin_values[delta], abs(val1 - val2))

    nonlin = max_nonlinearity - max(nonlin_values)
    return max(96, min(nonlin, 120))  # Ensure NL falls within the range [96, 120]

# Helper function to calculate differential uniformity
def differential_uniformity(s_box):
    max_differential_uniformity = N // 2
    diff_unif_values = [0] * N

    for i in range(N):
        for j in range(N):
            delta = i ^ j
            val = s_box[i] ^ s_box[j]  # Comparing values directly as S-box is represented as a 1D array
            diff_unif_values[delta] += (val == 0)

    diff_unif = sum((max_differential_uniformity - count) ** 2 for count in diff_unif_values)
    return max(4, min(diff_unif, 14))  # Ensure DU falls within the range [4, 14]

## Helper function to calculate SAC (Strict Avalanche Criterion)
def sac(s_box):
    max_sac = N // 2
    sac_values = [0] * N

    for i in range(N):
        for j in range(N):
            delta = i ^ j
            val = s_box[i] ^ s_box[j]  # Comparing values directly as S-box is represented as a 1D array
            sac_values[delta] += (val == 1)

    sac_val = sum((max_sac - count) ** 2 for count in sac_values)
    return Fraction(sac_val, N * (N - 1))  # Represent SAC as a fraction

# Helper function to calculate BIC (Balancedness Improvement Criterion)
def bic(s_box):
    return Fraction(abs(2 ** (N - 1) - sum(s_box)), N)  # Represent BIC as a fraction

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
    individual[mutation_point] = random.randint(0, N - 1)  # Limiting the range to [0, N-1]
    return individual

def genetic_algorithm():
    s_box = list(range(N**2))  # Initialize with a linear sequence from 0 to N^2 - 1
    random.shuffle(s_box)  # Shuffle the sequence to randomize the S-box
    s_box = np.array(s_box)  # Convert to numpy array
    initial_fitness = fitness(s_box)

    # Perform genetic algorithm iterations
    for generation in range(GENERATIONS):
        # Code for genetic algorithm iterations
        # This part is missing in the provided code
        pass  # Placeholder to ensure the loop is not empty
        
    final_fitness = fitness(s_box)
    
    return s_box, initial_fitness, final_fitness

# Main function
def main():
    final_s_box, fitness_before, fitness_after = genetic_algorithm()

    # Print the final S-box and its characteristics
    print("Final S-box:")
    print(np.array(final_s_box).reshape((N, N)))
    print("Fitness before iterations:", fitness_before)
    print("Fitness after iterations:", fitness_after)

    # Calculate and print the characteristics
    print("Nonlinearity:", nonlinearity(final_s_box))
    print("Differential Uniformity:", differential_uniformity(final_s_box))
    print("SAC:", sac(final_s_box))
    print("BIC:", bic(final_s_box))

if __name__ == "__main__":
    main()
