Authors: Storm van Rooden (s3520129) & Jonathan Hosea (s3712826)

TODO:
1. Abstract Syntax Tree bouwen
  Veranderd de node in een VAR | @ met eronder twee expressies | Lambda met eronder expressie. 
  Is nu alleen nog in EXPR gedaan (en niet getest).

  Token klasses moet nog worden aangemaakt om te onthouden wat de variable is (bijv: \X of \Y)
# ->
2. bound variables kunnen vinden in AST
3. functies voor alpha-conversion en beta-reduction maken
4. Herkennen wanneer (automatisch?) substitutie moet worden toegepast (expresie naast expressie?) 

BUGS:
- lege regels na de laatste expressie zorgt voor een foute expressie
- de parser moet weten wanneer een subboom / expressie stop.
  bij bijvoorbeeld \x a b staat eigenlijk ((\x (a)) b), maar de boom wordt nu gebouwd als (\x (a b)).