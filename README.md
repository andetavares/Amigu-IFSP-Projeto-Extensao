# AMIGU - Sistema Integrado de Gestão de Doações

Sistema desktop para organizar o recebimento, o estoque e a distribuição de doações da **Comunidade Resplandecer em Deus**.

Projeto de extensão desenvolvido no **IFSP Campus Campinas**, no curso de **Tecnologia em Análise e Desenvolvimento de Sistemas (TADS)**, para a disciplina **Gestão de Projetos**.

![Status](https://img.shields.io/badge/status-em%20desenvolvimento-yellow)
![Linguagem](https://img.shields.io/badge/linguagem-C-blue)
![Tipo](https://img.shields.io/badge/tipo-desktop-lightgrey)

---

## Índice

- [Sobre o projeto](#sobre-o-projeto)
- [Problema que o AMIGU resolve](#problema-que-o-amigu-resolve)
- [Objetivos](#objetivos)
- [Funcionalidades](#funcionalidades)
- [Histórias de usuário](#histórias-de-usuário)
- [Fora do escopo](#fora-do-escopo)
- [Tecnologias](#tecnologias)
- [Como compilar e executar](#como-compilar-e-executar)
- [Estrutura do repositório](#estrutura-do-repositório)
- [Cronograma e marcos](#cronograma-e-marcos)
- [Riscos](#riscos)
- [Segurança e privacidade](#segurança-e-privacidade)
- [Equipe e partes interessadas](#equipe-e-partes-interessadas)
- [Documentação do projeto](#documentação-do-projeto)
- [Como contribuir](#como-contribuir)

---

## Sobre o projeto

A Comunidade Resplandecer em Deus realiza ações de caridade sem fins lucrativos, recebendo e distribuindo alimentos, roupas e outros recursos para pessoas necessitadas. Hoje esse trabalho é feito de forma manual, com anotações e conversas diretas.

O **AMIGU** centraliza essas informações em um único sistema, permitindo cadastrar doadores e beneficiários, registrar doações, controlar o estoque (com data de validade dos alimentos e tamanho/faixa etária das roupas) e consultar o histórico das distribuições.

O sistema é desenvolvido inicialmente para a Comunidade Resplandecer em Deus, mas pode ser adaptado no futuro para outras instituições que façam trabalhos semelhantes.

## Problema que o AMIGU resolve

O processo manual atual está sujeito a:

- **Perda de informações** sobre os produtos recebidos e disponíveis para doação;
- **Desperdício** de alimentos que vencem sem que ninguém perceba;
- **Registros duplicados ou inconsistentes** de doadores e beneficiários;
- **Distribuição inadequada** dos recursos, com risco de fraudes e omissão da real condição dos beneficiários;
- **Muito tempo gasto** pelos voluntários na organização e na entrega das doações.

## Objetivos

**Objetivo geral:** desenvolver, até o final do segundo semestre de 2026, um sistema funcional que permita o cadastro e o gerenciamento de doadores, beneficiários e doações, além do controle de estoque de alimentos e roupas.

**Critérios de sucesso:**

- Produto final aprovado e utilizado pela Comunidade Resplandecer em Deus;
- Cumprimento dos prazos de entrega do protótipo e do produto final, conforme o cronograma acadêmico;
- Feedback formal e positivo da equipe da instituição ao final do projeto;
- Ganho de tempo e melhor controle dos beneficiários.

## Funcionalidades

### Usuários
- Cadastro de usuários e login com usuário e senha
- Controle básico de acesso

### Doadores
- Cadastro, edição e consulta
- Histórico de doações realizadas

### Beneficiários
- Cadastro, edição e consulta
- Necessidades identificadas e histórico de recebimentos

### Doações
- Registro de doações de alimentos e roupas
- Identificação do doador, tipo de produto, quantidade e data de recebimento
- Data de validade para alimentos
- Roupas catalogadas por sexo, tamanho e faixa etária

### Estoque
- Registro de entradas e saídas
- Consulta da quantidade disponível, organizada por categoria
- Controle de validade e identificação de produtos próximos do vencimento
- Atualização automática do estoque a cada doação recebida ou distribuída

### Histórico e relatórios
- Registro das distribuições realizadas (para quem, por quem, o quê)
- Consulta de distribuições anteriores
- Relatórios básicos: doações recebidas, estoque, produtos próximos do vencimento e distribuições
- Exportação de relatórios para Excel

## Histórias de usuário

| ID | História | Prioridade |
|----|----------|------------|
| US-001 | Como voluntário, quero fazer login com minhas credenciais para ser identificado pelo sistema de forma segura. | Alta |
| US-002 | Como voluntário, quero cadastrar beneficiários para que a instituição controle as pessoas que recebem assistência. | Alta/Normal |
| US-003 | Como voluntário, quero cadastrar doações de alimentos e roupas para que tudo seja registrado no estoque. | Alta |
| US-004 | Como voluntário, quero consultar e atualizar o estoque (quantidade, validade, tamanho e tipo) para saber o que está disponível e o que já foi doado. | Alta |
| US-005 | Como voluntário, quero consultar o histórico das doações e relatórios básicos para acompanhar a movimentação. | Normal |

## Fora do escopo

Para manter o projeto viável dentro do prazo, **não** fazem parte da versão inicial:

- Aplicativo mobile
- Integração com sistemas governamentais, bancos ou sistemas de pagamento
- Doação financeira online
- Inteligência artificial para identificação de beneficiários
- Geolocalização de doadores ou beneficiários
- Integração automática com WhatsApp ou redes sociais
- Reconhecimento facial ou biometria
- Infraestrutura própria de servidores
- Garantia automática de prevenção de fraudes

## Tecnologias

- **Linguagem:** C
- **Banco de dados:** relacional, gratuito ou de baixo custo (SGBD a ser confirmado pela equipe)
- **Editor:** Visual Studio Code
- **Compilador:** GCC
- **Controle de versão:** Git e GitHub
- **Comunicação da equipe:** WhatsApp, Discord e Google Drive

## Como compilar e executar

> O projeto está em fase inicial e os comandos abaixo podem mudar conforme o código evoluir.

**Pré-requisitos (Linux, Debian/Ubuntu/Zorin):**

```bash
sudo apt update
sudo apt install build-essential git
```

**Clonar o repositório:**

```bash
git clone https://github.com/andetavares/Amigu-IFSP-Projeto-Extensao.git
cd Amigu-IFSP-Projeto-Extensao
```

**Compilar e executar:**

```bash
gcc main.c -o amigu
./amigu
```

Se o programa usar outros arquivos-fonte (por exemplo `cadastro.c`) ou bibliotecas, inclua-os no comando de compilação, como em `gcc main.c cadastro.c -o amigu`.

## Estrutura do repositório

```
Amigu-IFSP-Projeto-Extensao/
├── docs/           # Documentos de gestão do projeto
├── main.c          # Ponto de entrada do programa
├── cadastro.c      # Módulo de cadastro
├── .gitignore      # Ignora executáveis e arquivos de compilação
├── LICENSE
└── README.md
```

## Cronograma e marcos

Planejamento pelo método do Caminho Crítico (CPM): cerca de **300 horas de trabalho da equipe**, com média de 15 horas por semana (esforço combinado do grupo), o que equivale a aproximadamente **5 meses**, deixando cerca de 1 mês de margem sobre o limite de 6 meses.

| Marco | Resultado esperado | Esforço acumulado |
|-------|--------------------|-------------------|
| M1 | Requisitos e escopo validados | 30 h |
| M2 | Banco de dados, telas e ambiente definidos | 60 h |
| M3 | Estrutura do programa e conexão com o banco funcionando | 90 h |
| M4 | Acesso e cadastros básicos implementados | 150 h |
| M5 | Doações, estoque e validade implementados | 210 h |
| M6 | Consultas e testes integrados concluídos | 270 h |
| M7 | Documentação, orientação e apresentação final | 300 h |

**Entregas principais:**

1. **Prova de conceito (Fase 1):** executável simples com o módulo de cadastro e o controle de cestas básicas em estoque;
2. **Protótipo funcional (Fase 2):** sistema completo com todos os recursos planejados;
3. **Manual do usuário:** documento em PDF, com orientação oral e presencial aos voluntários.

Em caso de atraso, os recursos opcionais são retirados primeiro, preservando cadastro, doações, estoque e validade.

## Riscos

| Risco | Descrição |
|-------|-----------|
| Disponibilidade da instituição | Dificuldade de reunir e validar requisitos com o responsável |
| Mudança de requisitos | Novas necessidades podem ampliar o escopo |
| Falta de informações | Pouco detalhe sobre o processo atual de doações |
| Limitação de tempo | O prazo acadêmico restringe funcionalidades complexas |
| Conhecimento técnico | A equipe pode encontrar tecnologias ainda não dominadas |
| Infraestrutura | Os computadores disponíveis podem ter limitações |
| Qualidade dos dados | Informações incompletas ou inconsistentes |
| Adoção do sistema | Dificuldade inicial de trocar o método manual pelo digital |
| Segurança e privacidade | Manipulação de dados de doadores e beneficiários |

## Segurança e privacidade

O sistema trabalha com dados de doadores e beneficiários, por isso prevê:

- Acesso somente por usuários cadastrados, com login e senha;
- Controle de permissões;
- Proteção das informações cadastradas e exposição mínima de dados pessoais;
- Histórico das principais movimentações;
- Uso de **dados fictícios** ou autorizados pela instituição durante o desenvolvimento e os testes.

> **Atenção:** este repositório é público. Nunca envie dados reais de doadores ou beneficiários, senhas ou tokens de acesso.

## Equipe e partes interessadas

**Equipe de desenvolvimento**

| Nome | Responsabilidade na comunicação |
|------|---------------------------------|
| Anderson Tavares Alexandre da Silva | Comunicação formal com o professor e comunicação técnica no GitHub |
| Gustavo Henrique Tofano Matos | Reuniões com o cliente e redação das atas |
| Milleni de Lima | Organização dos documentos no Google Drive |

**Orientação acadêmica:** Prof. Carlos Eduardo Beluzo (IFSP Campinas)

**Cliente:** Comunidade Resplandecer em Deus, representada pelo Pastor William Reis

**Outros envolvidos:** voluntários (usuários finais), doadores e beneficiários.

## Documentação do projeto

Os documentos de gestão elaborados pela equipe:

| Documento | Conteúdo |
|-----------|----------|
| Termo de Abertura do Projeto | Justificativa, entregas, critérios de sucesso, riscos e aprovações |
| Documento Base do Projeto | Visão geral, objetivo SMART, módulos, restrições e requisitos de segurança |
| Coleta de Requisitos | Stakeholders, entrevista, brainstorm, histórias de usuário, critérios de aceitação e priorização |
| EAP | Estrutura Analítica do Projeto |
| Planejamento CPM | Atividades, precedências, caminho crítico e marcos |
| Gerenciamento das Partes Interessadas | Classificação e estratégias de engajamento |
| Plano de Gerenciamento das Comunicações | Canais, eventos, responsáveis e diretrizes de comunicação |

## Como contribuir

O fluxo de trabalho da equipe é:

```bash
git pull                              # traz as novidades do GitHub
git status                            # mostra o que mudou
git add arquivo.c                     # prepara o arquivo
git commit -m "Descreve a alteração"  # registra a mudança
git push                              # envia para o GitHub
```

Boas práticas: faça commits pequenos e com mensagens claras, rode `git pull` antes de começar a trabalhar e não envie executáveis nem arquivos compilados (já ignorados pelo `.gitignore`).

---

Projeto acadêmico do **IFSP Campus Campinas** · TADS · Gestão de Projetos · 2026
