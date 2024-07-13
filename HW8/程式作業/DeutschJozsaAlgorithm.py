from qiskit import QuantumRegister, QuantumCircuit, ClassicalRegister,execute
from qiskit.providers.aer import AerSimulator

"""此處作為Oracle(黑箱)"""
def dj_problem_oracle(problem):
    """Returns a 5-qubit Deutsch-Joza Oracle"""
    qc = QuantumCircuit(5)
    int(problem)
    if problem == 1:
        for q in range(4):
            qc.cx(q, 4)
    elif problem == 2:
        qc.cx(0, 4)
        qc.cx(0, 4)
    elif problem == 3:
        qc.cx(2,4)
    else:
        print("There are only currently 3 oracles in this problem set, returning empty (balanced) gate")
    return qc.to_gate()

n = int(input())
for i in range(n):
    problem =  int(input())
    xreg = QuantumRegister(4,'x')
    yreg = QuantumRegister(1,'y')
    creg = ClassicalRegister(4,'c')
    qc = QuantumCircuit(xreg,yreg,creg)
    qc.h(xreg)
    qc.x(yreg)
    qc.h(yreg)
    qc.barrier()
    qc.append(dj_problem_oracle(problem),range(5))
    qc.barrier()
    qc.h(xreg)
    qc.measure(xreg,creg)
    #display(qc.draw('mpl'))
    sim = AerSimulator()
    job = execute(qc,backend=sim,shots=1000)
    result = job.result()
    counts = result.get_counts(qc)
    for count in counts:
        print(count)
