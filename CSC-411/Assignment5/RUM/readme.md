# Rust Universal Machine
## Overview

This assignment involves the implementation of a virtual machine, referred to as RUM (Rust Universal Machine), which is aimed at understanding virtual-machine code through software development in Rust. The assignment is split into two parts: design and implementation.

### Due Dates
- **Design**: Due by November 17th, 11:59 PM.
- **Implementation**: Due by December 1st, 11:59 PM.

## Purpose

The core purpose of this assignment is to gain a deeper understanding of machine code by writing a software implementation of a simple virtual machine. This involves dealing with aspects like machine state, instruction coding and semantics, and emulating a 32-bit machine on potentially different hardware.

## Specifications

- **Machine State**: Includes eight general-purpose registers, a segmented memory model, an I/O device, and a 32-bit program counter.
- **Instructions**: The machine recognizes 14 instructions, each identified by a unique opcode. Instructions cover operations like conditional move, segmented load/store, arithmetic operations, and program control instructions.
- **Failure Modes**: Detailed circumstances under which the machine may fail, like invalid program counter states, invalid instructions, and resource limitations.
- **Resource Exhaustion**: Guidelines on handling resource exhaustion scenarios.
- **Emulation and Abstractions**: Advice on emulating a 32-bit machine and choosing efficient abstractions, particularly in the context of a 64-bit environment.

## Expectations

### Design and Documentation
- Detailed documentation of the design, including the representation of segments, architecture, and a comprehensive test plan.
- Emphasis on high-quality design documentation, clearly defining data structures, system architecture, and unit testing approaches.

### Implementation
- A complete and efficient implementation of the Universal Machine.
- Performance benchmark: executing 50 million instructions in under 100 CPU seconds.
- Ensuring resource recovery after program execution, regardless of client behavior.

## Submission

### Design
- A PDF file describing the design to be submitted on Gradescope.

### Implementation
- The complete RUM project, zipped and excluding certain directories (`.git`, `target`, `Cargo.lock`).
- A README file covering:
  - Identification of contributors.
  - Acknowledgments of assistance or collaboration.
  - Status of implementation, noting any deviations from the design.
  - System architecture, module descriptions, and interrelationships.
  - Performance benchmarks and time spent on various aspects of the assignment.

### Additional Notes
- Expectations regarding the handling of input instructions, memory allocation, and common pitfalls.
- Guidance on testing, including the use of specific tools and strategies.

---

This README provides a concise overview of the assignment, its goals, specifications, and submission expectations. Adjustments can be made based on specific details or additional requirements of your project.
