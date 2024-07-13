from qiskit import QuantumCircuit,QuantumRegister,ClassicalRegister, Aer
from qiskit.visualization import array_to_latex
import numpy as np

vreg = QuantumRegister(2,'v')
cbits_reg = ClassicalRegister(2,'cbits')
qc = QuantumCircuit(vreg,cbits_reg)
qc.x(vreg[1])
qc.h(vreg)
qc.cx(vreg[0],vreg[1])

sim = Aer.get_backend('aer_simulator')
qc.save_unitary()
unitary = sim.run(qc).result().get_unitary()
print([['{:.2f}'.format(item) for item in sublist] for sublist in np.array(unitary)])
