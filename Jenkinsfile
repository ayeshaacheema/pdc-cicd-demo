pipeline {
    agent any

    stages {
        stage('Checkout') {
            steps {
                checkout scm
                sh 'git log -1 --oneline'
            }
        }
        stage('Build') {
            steps {
                sh 'gcc -fopenmp -O2 -o parallel_sum parallel_sum.c'
            }
        }
        stage('Test') {
            steps {
                sh '''
                    for t in 1 2 4; do
                        echo "== Testing with $t thread(s) =="
                        OMP_NUM_THREADS=$t ./parallel_sum
                    done
                '''
            }
        }
        stage('Run') {
            steps {
                sh 'OMP_NUM_THREADS=2 ./parallel_sum'
            }
        }
    }

    post {
        success { echo 'Pipeline succeeded' }
        failure { echo 'Pipeline failed' }
    }
}
